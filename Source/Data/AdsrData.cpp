/*
  ==============================================================================

    AdsrData.cpp
    Created: 14 Apr 2023 4:30:59am
    Author:  Артем Шелегович

  ==============================================================================
*/

#include "AdsrData.h"

void AdsrData::updateADSR (const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;
    
    setParameters(adsrParams);
}
