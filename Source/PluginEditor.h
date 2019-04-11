/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MoorerReverbAudioProcessorEditor  : public AudioProcessorEditor,
public Slider::Listener,
public Timer
{
public:
    MoorerReverbAudioProcessorEditor (MoorerReverbAudioProcessor&);
    ~MoorerReverbAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void sliderValueChanged(Slider* slider) override;
    void timerCallback() override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MoorerReverbAudioProcessor& processor;

    HackAudio::Slider reverbTimeSlider;
    HackAudio::Slider diffusionSlider;
    HackAudio::Slider modulationSlider;
    
    juce::Label reverbTimeLabel;
    juce::Label diffusionSliderLabel;
    juce::Label modulationSliderLabel;
    
    HackAudio::FlexBox flexSliders;

    
    int sliderSize = 80;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MoorerReverbAudioProcessorEditor)
};


