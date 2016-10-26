/*
  ==============================================================================

    FMSound.h
    Created: 19 Oct 2016 11:45:05pm
    Author:  yuanshenli

  ==============================================================================
*/

#ifndef FMSOUND_H_INCLUDED
#define FMSOUND_H_INCLUDED

struct FMSound : public SynthesiserSound
{
    FMSound() {}
    
    bool appliesToNote (int /*midiNoteNumber*/) override        { return true; }
    bool appliesToChannel (int /*midiChannel*/) override        { return true; }
};


#endif  // FMSOUND_H_INCLUDED
