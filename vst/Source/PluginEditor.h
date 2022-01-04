/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class VstAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    VstAudioProcessorEditor (VstAudioProcessor&);
    ~VstAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VstAudioProcessor& audioProcessor;
    
    // MIDI Keyboard // 
    juce::MidiKeyboardState keyboardState;
    juce::MidiKeyboardComponent keyboardComponent{ keyboardState,
        juce::MidiKeyboardComponent::horizontalKeyboard };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstAudioProcessorEditor)
};
