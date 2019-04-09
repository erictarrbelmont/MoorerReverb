/*
 ==============================================================================
 
 Delay.h
 Created: 4 Apr 2019 1:28:00pm
 Author:  Mary Lindsey
 
 ==============================================================================
 */

#ifndef Delay_h
#define Delay_h
#include <math.h>

class Delay{
    
public:
    
    float processSample(float x, int channel);
    
    
    void setFs(int Fs);
    
    float getFs();
    
    
    void setDelayTime(float d);
    
    float getDelayTime();
    
    
    void setModAmp(float m);
    
    float getModAmp();
    
    
    void setFreqLFO(float f);
    
    float getFreqLFO();
    
    float lfo();
    
    float delay=0.0f;
    float modAmp=0.0f;
    float freqLFO=0.0f;
    float sinSynth(float angle);
private:
    
    float Fs = 48000.f;
    
    
    
    
    
};

#endif /* Delay_h */
