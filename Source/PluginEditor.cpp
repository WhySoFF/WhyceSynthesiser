/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ShelSynthAudioProcessorEditor::ShelSynthAudioProcessorEditor (ShelSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc (audioProcessor.apvts, "OSC1WAVETYPE", "OSC1FMFREQ", "OSC1FMDEPTH"), adsr (audioProcessor.apvts)
{
    setSize (400, 300);
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
    
}

ShelSynthAudioProcessorEditor::~ShelSynthAudioProcessorEditor()
{
}

//==============================================================================
void ShelSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
    g.setColour(juce::Colours::white);
    g.drawRect(getLocalBounds());
    
}

void ShelSynthAudioProcessorEditor::resized()
{
    osc.setBounds(10, 10, 180, 200);
    adsr.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}


