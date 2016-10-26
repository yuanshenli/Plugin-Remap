/*
  ==============================================================================

    SynthAudioSource.h
    Created: 19 Oct 2016 11:48:30pm
    Author:  yuanshenli

  ==============================================================================
*/

#ifndef SYNTHAUDIOSOURCE_H_INCLUDED
#define SYNTHAUDIOSOURCE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "FMSound.h"
#include "FMVoice.h"

struct SynthAudioSource
{
    SynthAudioSource ()
    {
        // Add some voices to our synth, to play the sounds..
        int nVoices = 4;
        for (int i = nVoices; --i >= 0;)
        {
            synth.addVoice (&fmVoice[i]);
        }
        
        synth.clearSounds();
        synth.addSound (new FMSound());
    }
    
    void prepareToPlay (int /*samplesPerBlockExpected*/, double sampleRate)
    {
        midiCollector.reset (sampleRate);
        synth.setCurrentPlaybackSampleRate (sampleRate);
    }
    
    void getNextAudioBlock(AudioSampleBuffer& audioBuffer, MidiBuffer& midiBuffer)
    {
        // the synth always adds its output to the audio buffer, so we have to clear it
        // first..
        audioBuffer.clear();
        
        
        // and now get the synth to process the midi events and generate its output.
        synth.renderNextBlock(audioBuffer, midiBuffer, 0, audioBuffer.getNumSamples());
    }
    
    // this collects real-time midi messages from the midi input device, and
    // turns them into blocks that we can process in our audio callback
    MidiMessageCollector midiCollector;
    
    // the synth itself!
    Synthesiser synth;
    FMVoice fmVoice[4];
};



#endif  // SYNTHAUDIOSOURCE_H_INCLUDED
