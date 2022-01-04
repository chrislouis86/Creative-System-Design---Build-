/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VstAudioProcessorEditor::VstAudioProcessorEditor (VstAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 400);
    
    // this function adds the slider to the editor
    addAndMakeVisible(&keyboardComponent);

    
}

VstAudioProcessorEditor::~VstAudioProcessorEditor()
{
    //keyboardComponent.setMidiChannel(2);
    keyboardState.removeListener (&audioProcessor.getMidiMessageCollector());
}

//==============================================================================
void VstAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("VST Instrument", getLocalBounds(), juce::Justification::centredTop, 1);
}

void VstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    keyboardState.removeListener (&audioProcessor.getMidiMessageCollector());
    
    // sets the position and size of the slider with arguments (x, y, width, height)
    //midiVolume.setBounds(40, 30, 20, getHeight() - 60);
    keyboardComponent.setBounds(20, 325, getWidth() - 25, 75);
}
