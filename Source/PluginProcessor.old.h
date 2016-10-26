// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple JUCE sine wave synthesizer plug-in

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Sine.h"
#include "FMSound.h"
#include "FMVoice.h"
#include "SynthAudioSource.h"


//==============================================================================
/**
*/
class BasicAudioPlugInAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    BasicAudioPlugInAudioProcessor();
    ~BasicAudioPlugInAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void SynthAudioSource (MidiKeyboardState& keyState);

    Sine sine;
    
    float onOff, gain;
    int samplingRate;
    
    AudioDeviceManager audioDeviceManager;
    AudioSourcePlayer audioSourcePlayer;
    
private:
    float** audioBuffer;
    int nChans;
    
    
    struct SynthAudioSource synthAudioSource;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicAudioPlugInAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
