/*
  ==============================================================================

    FMVoice.h
    Created: 19 Oct 2016 11:30:06pm
    Author:  yuanshenli

  ==============================================================================
*/

#ifndef FMVOICE_H_INCLUDED
#define FMVOICE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Sine.h"
#include "Smooth.h"
#include "FMSound.h"

// The FM synth voice. The FM synth is hardcoded here but ideally it should be in its own class
// to have a clear hierarchy (Sine -> FMSynth -> FMVoice)
struct FMVoice : public SynthesiserVoice
{
    FMVoice();

    bool canPlaySound (SynthesiserSound* sound) override;

    void startNote (int midiNoteNumber, float velocity,
                    SynthesiserSound*, int /*currentPitchWheelPosition*/) override;

    void stopNote (float /*velocity*/, bool allowTailOff) override;

    void pitchWheelMoved (int /*newValue*/) override;

    void controllerMoved (int /*controllerNumber*/, int /*newValue*/) override;

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    
    int noteMapped[128];

private:
    Sine carrier, modulator;
    Smooth smooth[2];
    double carrierFrequency, index, level, envelope;
    bool onOff, tailOff;
    

};


#endif  // FMVOICE_H_INCLUDED
