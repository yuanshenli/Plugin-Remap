// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple JUCE sine wave synthesizer plug-in

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SynthAudioSource.h"


//==============================================================================
/**
*/


class BasicAudioPlugInAudioProcessorEditor  :
public AudioProcessorEditor,
//public juce::MidikeyboardComponent,
private ComboBox::Listener,
private MidiInputCallback
{
public:
    BasicAudioPlugInAudioProcessorEditor (BasicAudioPlugInAudioProcessor&);
    ~BasicAudioPlugInAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void comboBoxChanged (ComboBox* box) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BasicAudioPlugInAudioProcessor& processor;
    
    MidiKeyboardState keyboardState;
    MidiKeyboardComponent keyboardComponent;
    
    ComboBox midiInputList;
    Label midiInputListLabel;
    int lastMidiInputIndex;
    
    void setMidiInput (int index);
    
    // Needed virtual function
    void handleIncomingMidiMessage (MidiInput*, const MidiMessage& message) override {}

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicAudioPlugInAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
