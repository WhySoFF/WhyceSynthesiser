/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ShelSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ShelSynthAudioProcessorEditor (ShelSynthAudioProcessor&);
    ~ShelSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    void setSliderParams (juce::Slider& slider);
    
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    juce::ComboBox oscSelector;
    
    using sliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    std::unique_ptr<sliderAttachment> attackAttachment;
    std::unique_ptr<sliderAttachment> decayAttachment;
    std::unique_ptr<sliderAttachment> sustainAttachment;
    std::unique_ptr<sliderAttachment> releaseAttachment;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;
    
    ShelSynthAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShelSynthAudioProcessorEditor)
};
