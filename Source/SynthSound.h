/*
  ==============================================================================

    SynthSound.h
    Created: 13 Apr 2023 2:38:18am
    Author:  Артем Шелегович

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber) override { return true; }
    bool appliesToChannel (int midiChannel) override { return true; }
    
};
