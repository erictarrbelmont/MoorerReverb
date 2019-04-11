/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MoorerReverbAudioProcessorEditor::MoorerReverbAudioProcessorEditor (MoorerReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    //reverb time, diffusion, modulation knobs
    
    reverbTimeSlider.addListener(this);
    reverbTimeSlider.setSize(sliderSize,sliderSize);
    reverbTimeSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    reverbTimeSlider.setRange(0, 1); // slider can have values between 0 and 1
    reverbTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
    reverbTimeSlider.setValue(1.0f);
    addAndMakeVisible(reverbTimeSlider);
    
    reverbTimeLabel.setText("Reverb Time", dontSendNotification);
    reverbTimeLabel.setJustificationType(Justification::centred);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider, false);
    // 'false' is to put it on top
    addAndMakeVisible(reverbTimeLabel);
    
    diffusionSlider.addListener(this);
    diffusionSlider.setSize(sliderSize,sliderSize);
    diffusionSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    diffusionSlider.setRange(0.1f, 10.0f); // slider can have values between 0 and 1
    diffusionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
    diffusionSlider.setValue(1.0f);
    addAndMakeVisible(diffusionSlider);
    
    diffusionSliderLabel.setText("Diffusion", dontSendNotification);
    diffusionSliderLabel.setJustificationType(Justification::centred);
    diffusionSliderLabel.attachToComponent(&diffusionSlider, false);
    // 'false' is to put it on top
    addAndMakeVisible(diffusionSliderLabel);
    
    modulationSlider.addListener(this);
    modulationSlider.setSize(sliderSize,sliderSize);
    modulationSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    modulationSlider.setRange(0.0f, 1.0f); // slider can have values between 0 and 1
    modulationSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
    modulationSlider.setValue(1.0f);
    addAndMakeVisible(modulationSlider);
    
    modulationSliderLabel.setText("Modulation", dontSendNotification);
    modulationSliderLabel.setJustificationType(Justification::centred);
    modulationSliderLabel.attachToComponent(&modulationSlider, false);
    // 'false' is to put it on top
    addAndMakeVisible(modulationSliderLabel);

    //Flex box for knobs
    flexSliders.addComponent(reverbTimeSlider);
    flexSliders.addComponent(diffusionSlider);
    flexSliders.addComponent(modulationSlider);
    
    flexSliders.applyBounds(juce::Rectangle<int>(20,150,(4*sliderSize)+40,sliderSize));

}

MoorerReverbAudioProcessorEditor::~MoorerReverbAudioProcessorEditor()
{
}

//==============================================================================
void MoorerReverbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::firebrick);

    Font titleFont = HackAudio::Fonts::NowBold;
    titleFont.setHeight(30);
    
    g.setFont(titleFont);
    g.drawFittedText ("Moorer",0, 20, 250, 25, Justification::centred, 1.0);
    g.setColour(Colours::white);
    g.drawFittedText ("Reverb",0, 20, 500, 25, Justification::centred, 1.0);
}

void MoorerReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void MoorerReverbAudioProcessorEditor::sliderValueChanged(Slider* slider){

    
    if (slider == &reverbTimeSlider){
//        processor.hpf1.setAmount(slider->getValue());
//        processor.softClip1.setDrive(slider->getValue());
//        reverbTimeLabel.setText(String(hpfSlider.getValue(),1),dontSendNotification);
    }
    
    if (slider == &diffusionSlider){
//        *processor.tremoloFreq = slider->getValue();
//        diffusionSliderLabel.setText(String(freqSlider.getValue(),1),dontSendNotification);
    }
    
    if (slider == &modulationSlider){
//        *processor.tremoloDepth = slider->getValue();
//        modulationSliderLabel.setText(String(depthSlider.getValue(),1),dontSendNotification);
    }
    
    startTimer(1200);
    
    
}

void MoorerReverbAudioProcessorEditor::timerCallback()
{
    stopTimer();
   
    reverbTimeLabel.setText("Reverb Time", dontSendNotification);
    diffusionSliderLabel.setText("Diffusion", dontSendNotification);
    modulationSliderLabel.setText("Modulation", dontSendNotification);
    
}
