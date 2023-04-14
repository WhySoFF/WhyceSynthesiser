/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"
#include "UI/OscComponent.h"

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
    
    
    ShelSynthAudioProcessor& audioProcessor;
    OscComponent osc;
    AdsrComponent adsr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShelSynthAudioProcessorEditor)
};
