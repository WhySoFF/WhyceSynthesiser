/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 14 Apr 2023 4:29:47am
    Author:  Артем Шелегович

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent(juce::AudioProcessorValueTreeState& apvts)
{
    using sliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    attackAttachment = std::make_unique<sliderAttachment>(apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<sliderAttachment>(apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<sliderAttachment>(apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<sliderAttachment>(apvts, "RELEASE", releaseSlider);

    setSliderParams (attackSlider);
    setSliderParams (decaySlider);
    setSliderParams (sustainSlider);
    setSliderParams (releaseSlider);
}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
}

void AdsrComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight();
    const auto sliderStartX = 0;
    const auto sliderStartY = 0;
    //const auto sliderStartY = bounds.getHeight() / 2 - (sliderHeight / 2);
    
    
    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);

}

void AdsrComponent::setSliderParams (juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}
