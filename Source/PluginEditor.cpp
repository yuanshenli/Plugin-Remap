/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
NewPlugInAudioProcessorEditor::NewPlugInAudioProcessorEditor (NewPlugInAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    width = 600;
    height = 400;

    for (int i = 0; i < 128; i++){
        circles.emplace_back(new CircleComponent());
    }
    for (int i = 0; i < 128; i++){
        addAndMakeVisible(*circles[i]);
    }
    
    setSize (width, height);
    
    addAndMakeVisible(randomSlider);
    randomSlider.setSliderStyle(Slider::Rotary);
    randomSlider.setColour(Slider::rotarySliderFillColourId , Colours::orange);
    randomSlider.setColour(Slider::rotarySliderOutlineColourId  , Colours::orange);
    randomSlider.setRange (0, 7, 1);
    randomSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    randomSlider.setValue(0);
    randomSlider.addListener(this);
    
}

NewPlugInAudioProcessorEditor::~NewPlugInAudioProcessorEditor()
{
}

//==============================================================================
void NewPlugInAudioProcessorEditor::paint (Graphics& g)
{
    File f = (String)"/Users/yuanshenli/Desktop/BasicAudioPlugIn/Source/data/backgnd.jpg";
    Image img = ImageFileFormat::loadFrom(f);
    g.drawImage(img,0,0,width,height,0,0,img.getWidth(), img.getHeight());
}

void NewPlugInAudioProcessorEditor::resized()
{
    int sliderSize = 200;
    
    randomSlider.setBounds (width/2-sliderSize/2, height/2-sliderSize/2, sliderSize, sliderSize);
    
    
    for(int i = 0; i < 128 ; i++) {
        circles[i]->setBounds(rand() % width, rand()%height, 35,35);
        circles[i]->setVisible(false);
    }
}

void NewPlugInAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    int nVoices = 4;
    random = (int)randomSlider.getValue();
    intervalNum = exp2((double)random);
    for (int i = 0; i < 128; i++) {
        noteMapped[i] = i;
    }
    for (int j = 0; j < 128/intervalNum; j++){
        for(int k = 0; k < intervalNum; k++){
            std::random_shuffle(&noteMapped[j*intervalNum], &noteMapped[(j+1)*intervalNum-1]);
        }
        
    }
    for(int j = 0; j < 128; j++) {
        for (int i = nVoices; --i >= 0;) {
            processor.audioSource.fmVoice[i].noteMapped[j] = noteMapped[j];
        }
        
    }
    for (int i = 0; i < 128; i++){
        if (i < intervalNum){
            circles[i]->setVisible(true);
        } else {
            circles[i]->setVisible(false);
        }
        
    }
    
    
}
