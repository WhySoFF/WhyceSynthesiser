/*
  ==============================================================================

    OscData.h
    Created: 14 Apr 2023 3:06:14pm
    Author:  Артем Шелегович

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay (juce::dsp::ProcessSpec& spec);
    void setWaveType(const int choice);
    void setWaveFrequency (const int midiNoteNumber);
    void getNextAudioBlock (juce::dsp::AudioBlock<float>& block);
    
private:
    
    
};
