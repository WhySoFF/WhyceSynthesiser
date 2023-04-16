#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"
#include "UI/OscComponent.h"
#include "UI/FilterComponent.h"
#include "UI/LfoComponent.h"
#include "UI/ReverbComponent.h"
#include "UI/MeterComponent.h"
#include "UI/Assets.h"

//==============================================================================
/**
*/
class ShelSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
, public juce::Timer
{
public:
    ShelSynthAudioProcessorEditor (ShelSynthAudioProcessor&);
    ~ShelSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void timerCallback() override;

private:
    
    
    ShelSynthAudioProcessor& audioProcessor;
    OscComponent osc1;
    OscComponent osc2;
    AdsrComponent adsr;
    FilterComponent filter;
    LfoComponent lfo1;
    AdsrComponent filterAdsr;
    ReverbComponent reverb;
    MeterComponent meter;
    juce::ImageComponent logo;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShelSynthAudioProcessorEditor)
};
