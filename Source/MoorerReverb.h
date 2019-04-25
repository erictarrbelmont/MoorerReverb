/*
  ==============================================================================

    MoorerReverb.h
    Created: 4 Apr 2019 1:32:53pm
    Author:  Sean Newell, Rober Coomber

  ==============================================================================
*/

#ifndef MoorerReverb_h
#define MoorerReverb_h
#include "APF.h"
#include "FBCF.h"
#include "EarlyReflections.h"

class MoorerReverb {
    
public:
    MoorerReverb();
    
    float processSample(float x, int channel);
    
    void setReverbTime(float rTime);
    
    void setDiffusion(float difValue);
    
    void setSamplingRate(int sampleRate);
    
    void setModulation(float modValue);

    APF apf1;
    APF apf2;
    FBCF fbcf1;
    FBCF fbcf2;
    FBCF fbcf3;
    FBCF fbcf4;
    EarlyReflections er1;
    
    
private:
    int Fs = 48000;
};
#endif
