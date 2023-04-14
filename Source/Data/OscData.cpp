/*
  ==============================================================================

    OscData.cpp
    Created: 14 Apr 2023 3:06:14pm
    Author:  Артем Шелегович

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec &spec)
{
    prepare(spec);
}

void OscData::setWaveType(const int choice)
{
    switch (choice) {
        case 0:
            //sinWave
            initialise([](float x) {return std::sin (x); });
            break;
            
        case 1:
            //sawWave
            initialise([](float x) {return  x / juce::MathConstants<float>::pi; });
            break;
            
        case 2:
            //squareWave
            initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f; });
            break;
            
        default:
            jassertfalse;
            break;
    }
}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}

void OscData::getNextAudioBlock (juce::dsp::AudioBlock<float>& block)
{
    process(juce::dsp::ProcessContextReplacing<float> (block));
}
