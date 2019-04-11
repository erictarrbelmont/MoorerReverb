/*
  ==============================================================================

    APF.h
    Created: 4 Apr 2019 1:32:14pm
    Author:  Justin Zemgulys

  ==============================================================================
*/

#ifndef APF_h
#define APF_h

#include <math.h>
#include "Delay.h"

class APF {
    
public:
    
    APF(){};
    ~APF(){};
    
    float processSample(float x,int channel);
    
    void setFs(float Fs);
    float getFs();
    
    void setDelaySamples(float delaySamples);
    float getDelaySamples();
    
    void setDelayMs(float delayMs);
    float getDelayMs();
    
    void setGain(float gain);
    float getGain();
    
    void setModAmp(float m);
    void setFreqLFO(float f);
    
private:

    float Fs;
    float delaySamples;
    float delayMs;
    float gain;
    
    Delay delay;
    
    float d1 = 0.0f;
};


#endif /* APF_h */
