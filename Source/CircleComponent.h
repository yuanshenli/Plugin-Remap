/*
  ==============================================================================

    CircleComponent.h
    Created: 25 Oct 2016 4:33:05pm
    Author:  yuanshenli

  ==============================================================================
*/

#ifndef CIRCLECOMPONENT_H_INCLUDED
#define CIRCLECOMPONENT_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"

class CircleComponent   : public Component
{
public:
    CircleComponent()
    {
    }
    
    ~CircleComponent()
    {
    }
    
    void paint (Graphics& g) override
    {
        g.setColour (Colour(rand()*255, rand()*255,rand()*255));
        size = 5 + rand() % 30;
        g.fillRoundedRectangle(0, 0, size, size, ((float)size-1.0)/2.5);
//        g.fillRoundedRectangle(0, 0, 10, 10, 5);
    }
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CircleComponent)
    float size;
};


#endif  // CIRCLECOMPONENT_H_INCLUDED
