/*
  ==============================================================================

    MoorerReverb.cpp
    Created: 4 Apr 2019 1:32:53pm
    Author:  Sean Newell, Rober Coomber

  ==============================================================================
*/

#ifndef MoorerReverb_cpp
#define MoorerReverb_cpp
#include "MoorerReverb.h"

MoorerReverb::MoorerReverb(){
    fbcf1.setDelayInSamples(1426);
    fbcf2.setDelayInSamples(1781);
    fbcf3.setDelayInSamples(1973);
    fbcf4.setDelayInSamples(2098);
    
    fbcf1.setGain(0.7f);
    fbcf2.setGain(0.7f);
    fbcf3.setGain(0.7f);
    fbcf4.setGain(0.7f);
    
    apf1.setDelaySamples(240);
    apf2.setDelaySamples(82);
    
    
};


float MoorerReverb::processSample(float x, int channel){
    
    // Send input into early reflections
    // x = ER.processSample(x, channel);
    
    // Send input into each FBCF
    float x1 = fbcf1.processSample(x,channel);
    float x2 = fbcf2.processSample(x,channel);
    float x3 = fbcf3.processSample(x,channel);
    float x4 = fbcf4.processSample(x,channel);
    
    // Sum the FBCFs together
    x = x1 + x2 + x3 + x4;
    
    // Send processed input into APFs
    x = apf1.processSample(x, channel);
    x = apf2.processSample(x, channel);
    
    float y = x;
    
    return y;
};

void MoorerReverb::setReverbTime(float gain){
    fbcf1.setGain(gain + 0.06);
    fbcf2.setGain(gain - 0.07);
    fbcf3.setGain(gain);
    fbcf3.setGain(gain - .04);
}



#endif














