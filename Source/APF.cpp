/*
  ==============================================================================

    APF.cpp
    Created: 4 Apr 2019 1:32:14pm
    Author:  Justin Zemgulys

  ==============================================================================
*/

#include "APF.h"
#include <math.h>


float APF::processSample(float x,int channel){
    
    // Output, processed sample (Direct Form 1)
    float y = (b0/a0)*x + (b1/a0)*x1[channel] + (b2/a0)*x2[channel] + (-a1/a0)*y1[channel] + (-a2/a0)*y2[channel];
    
    x2[channel] = x1[channel]; // store delay samples for next process step
    x1[channel] = x;
    y2[channel] = y1[channel];
    y1[channel] = y;
    
    return y;
    
};


void APF::setFs(float Fs){
    if (Fs == 44100 || Fs == 48000 || Fs == 88200 || Fs == 96000 || Fs == 192000){
        this->Fs = Fs;
        updateCoefficients(); // Need to update if Fs changes
    }
    
};
float APF::getFs(){
    return Fs;
};


void APF::setFreq(float freq){
    if (freq <= 20000.0f) {
        if (freq >= 20.0f){
            this->freq = freq;
            
            w0 = 2 * M_PI * freq/Fs; // Normalize frequency
            alpha = sinf(w0)/(2.0f*Q); // Bandwidth/slope/resonance parameter
            
            updateCoefficients();
        }
    }
    
};
float APF::getFreq(){
    return freq;
};


void APF::setQ(float Q){
    if (Q <= 10.0f) {
        if (Q >= 0.1f){
            this->Q = Q;
            
            alpha = sinf(w0)/(2.0f*Q); // Bandwidth/slope/resonance parameter
            
            updateCoefficients();
        }
    }
    
};
float APF::getQ(){
    return Q;
};

void APF::setAmpdB(float ampdB){
    if (ampdB <= 18.0f) {
        if (ampdB >= -18.0f){
            this->ampdB = ampdB;
            
            A = powf(10.0f,ampdB/40.0f); // Linear amplitude
            
            updateCoefficients();
        }
    }
    
};
float APF::getAmpdB(){
    return ampdB;
};

void APF::updateCoefficients(){
    b0 =   1.0f - alpha;
    b1 =  -2.0f*cosf(w0);
    b2 =   1.0f + alpha;
    a0 =   1.0f + alpha;
    a1 =  -2.0f*cosf(w0);
    a2 =   1.0f - alpha;
};
