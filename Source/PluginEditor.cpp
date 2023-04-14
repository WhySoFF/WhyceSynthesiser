/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ShelSynthAudioProcessorEditor::ShelSynthAudioProcessorEditor (ShelSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    
    using sliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    attackAttachment = std::make_unique<sliderAttachment>(audioProcessor.apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<sliderAttachment>(audioProcessor.apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<sliderAttachment>(audioProcessor.apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<sliderAttachment>(audioProcessor.apvts, "RELEASE", releaseSlider);
    
    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "OSC", oscSelector);
    
    setSliderParams (attackSlider);
    setSliderParams (decaySlider);
    setSliderParams (sustainSlider);
    setSliderParams (releaseSlider);
    
    
}

ShelSynthAudioProcessorEditor::~ShelSynthAudioProcessorEditor()
{
}

//==============================================================================
void ShelSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey); 
}

void ShelSynthAudioProcessorEditor::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getWidth() / 4 - padding;
    const auto sliderStartX = 0;
    const auto sliderStartY = bounds.getHeight() / 2 - (sliderHeight / 2);
    
    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
}

void ShelSynthAudioProcessorEditor::setSliderParams (juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}
