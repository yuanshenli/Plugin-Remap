// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple JUCE sine wave synthesizer plug-in

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
BasicAudioPlugInAudioProcessorEditor::BasicAudioPlugInAudioProcessorEditor (BasicAudioPlugInAudioProcessor& p) : AudioProcessorEditor (&p), processor (p), lastMidiInputIndex (0), keyboardComponent (keyboardState, MidiKeyboardComponent::horizontalKeyboard)
{
    
    
    // MIDI Inputs
    addAndMakeVisible (midiInputListLabel);
    midiInputListLabel.setText ("MIDI Input:", dontSendNotification);
    midiInputListLabel.attachToComponent (&midiInputList, true);
    
    // menu listing all the available MIDI inputs
    addAndMakeVisible (midiInputList);
    midiInputList.setTextWhenNoChoicesAvailable ("No MIDI Inputs Enabled");
    const StringArray midiInputs (MidiInput::getDevices());
    midiInputList.addItemList (midiInputs, 1);
    midiInputList.setSelectedId(0); // default
    midiInputList.addListener (this);
    
    // by default we use the first MIDI input
    setMidiInput(0);
    
    // The MIDI keyboard
    addAndMakeVisible(keyboardComponent);
    
    processor.onOff = 1.0;
    
    setSize (600, 100);
}

BasicAudioPlugInAudioProcessorEditor::~BasicAudioPlugInAudioProcessorEditor()
{
    processor.audioDeviceManager.removeMidiInputCallback (MidiInput::getDevices()[midiInputList.getSelectedItemIndex()], this);
    midiInputList.removeListener (this);
}

//==============================================================================
void BasicAudioPlugInAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::lightgrey);
}

void BasicAudioPlugInAudioProcessorEditor::resized()
{
    const int labelWidth = 90;
    midiInputList.setBounds (labelWidth, 0, getWidth()-labelWidth, 20);
    keyboardComponent.setBounds (0, 30, getWidth(), 64);
}

void BasicAudioPlugInAudioProcessorEditor::comboBoxChanged (ComboBox* box)
{
    if (box == &midiInputList) {
        setMidiInput  (midiInputList.getSelectedItemIndex());
    }
}

void BasicAudioPlugInAudioProcessorEditor::setMidiInput(int index)
{
    const StringArray list (MidiInput::getDevices());
    
    processor.audioDeviceManager.removeMidiInputCallback (list[lastMidiInputIndex], this);
    
    const String newInput (list[index]);
    
    if (! processor.audioDeviceManager.isMidiInputEnabled (newInput))
        processor.audioDeviceManager.setMidiInputEnabled (newInput, true);
    
    processor.audioDeviceManager.addMidiInputCallback (newInput, this);
    midiInputList.setSelectedId (index + 1, dontSendNotification);
    
    lastMidiInputIndex = index;
}

