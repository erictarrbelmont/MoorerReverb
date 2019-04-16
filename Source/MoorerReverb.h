/*
  ==============================================================================

    MoorerReverb.h
    Created: 4 Apr 2019 1:32:53pm
    Author:  Sean Newell, Rober Coomber

  ==============================================================================
*/

#ifndef MoorerReverb_h
#define MoorerReverb_h
//#pragma once
#include "APF.h"
#include "FBCF.cpp"

class MoorerReverb {
    
public:
    
    MoorerReverb();

    
    float processSample(float x, int channel);
    
    void setReverbTime(float gain);
    
    float getReverbTime();
    
    void setDiffusion(float samples);
    
    float getDiffusion();
    
    void setModulation(float samples);
    
    float getModulation();
    
    void setSamplingRate(int sampleRate);
    
    int getSamplingRate();
    
    
    APF apf1;
    APF apf2;
    FBCF fbcf1;
    FBCF fbcf2;
    FBCF fbcf3;
    FBCF fbcf4;
    //ER er1;
    
    
private:
    
};
#endif
