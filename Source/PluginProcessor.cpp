/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MoorerReverbAudioProcessor::MoorerReverbAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
treeState (*this, nullptr, Identifier ("MoorerParams"), createParameterLayout() )
{
    
     thisMoorerReverb = new MoorerReverb();
    
    reverbTimeParameter = treeState.getRawParameterValue("reverbTime");
    diffusionParameter = treeState.getRawParameterValue("diffusion");
    modulationParameter = treeState.getRawParameterValue("modulation");
    
}

MoorerReverbAudioProcessor::~MoorerReverbAudioProcessor()
{
    delete thisMoorerReverb;
}

AudioProcessorValueTreeState::ParameterLayout MoorerReverbAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
   auto reverbTimeParams = std::make_unique<AudioParameterFloat> ("reverbTime","ReverbTime", 0.2,0.9,0.7);
    auto diffusionParams = std::make_unique<AudioParameterFloat> ("diffusion","Diffusion",0.2,0.9,0.7);
    auto modulationParams = std::make_unique<AudioParameterFloat> ("modulation","Modulation", 0.2,0.9,0.7);

    params.push_back(std::move(reverbTimeParams));
    params.push_back(std::move(diffusionParams));
    params.push_back(std::move(modulationParams));

    return { params.begin(), params.end() };
    
}

//==============================================================================
const String MoorerReverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MoorerReverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MoorerReverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MoorerReverbAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MoorerReverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MoorerReverbAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MoorerReverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MoorerReverbAudioProcessor::setCurrentProgram (int index)
{
}

const String MoorerReverbAudioProcessor::getProgramName (int index)
{
    return {};
}

void MoorerReverbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MoorerReverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    thisMoorerReverb->setSamplingRate(getSampleRate());
}

void MoorerReverbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MoorerReverbAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MoorerReverbAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    
    auto reverb = *reverbTimeParameter;
    auto diffusion = *diffusionParameter;
    auto modulation = *modulationParameter;
    
    
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    //TODO: Implement input params
    thisMoorerReverb->setDiffusion(diffusion);
    thisMoorerReverb->setReverbTime(reverb);
    thisMoorerReverb->setModulation(modulation);
    
    //auto* channelData = buffer.getWritePointer (channel);
    for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {
       
            
            float x = buffer.getReadPointer(channel)[sample];
            
            buffer.getWritePointer(channel)[sample] = thisMoorerReverb->processSample(x, channel);

        }
    }
}

//==============================================================================
bool MoorerReverbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MoorerReverbAudioProcessor::createEditor()
{
    return new MoorerReverbAudioProcessorEditor (*this);
}

//==============================================================================
void MoorerReverbAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    auto state = treeState.copyState();
    std::unique_ptr<XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
    
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MoorerReverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (treeState.state.getType()))
            treeState.replaceState (ValueTree::fromXml (*xmlState));
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MoorerReverbAudioProcessor();
}
