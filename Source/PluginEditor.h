/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "CircleComponent.h"


//==============================================================================
/**
*/
class NewPlugInAudioProcessorEditor  :
public AudioProcessorEditor,
private Slider::Listener
{
public:
    NewPlugInAudioProcessorEditor (NewPlugInAudioProcessor&);
    ~NewPlugInAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* slider) override;
    int noteMapped[128];

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NewPlugInAudioProcessor& processor;
    Slider randomSlider;
    int intervalNum;
    int random;
    Image img;
    int width, height;
    std::vector<std::shared_ptr<CircleComponent>> circles;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewPlugInAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
