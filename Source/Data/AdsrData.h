/*
  ==============================================================================

    AdsrData.h
    Created: 14 Apr 2023 4:30:59am
    Author:  Артем Шелегович

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void updateADSR (const float attack, const float decay, const float sustain, const float release);
    
private:
    juce::ADSR::Parameters adsrParams;
};
