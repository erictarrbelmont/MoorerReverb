/*
 ==============================================================================
 
 Delay.cpp
 Created: 4 Apr 2019 1:28:00pm
 Author:  Mary Lindsey
 
 ==============================================================================
 */

#include "Delay.h"
#include <math.h>
float processSample(float x, int channel){
    float y = 0;
    float maxBufferSize[96000];
    float index = 0;
    int d1 = floorf(delay);
    int d2 = d1 + 1;
    float g2 = delay - d1;
    float g1 = 1.0f - g2;
    
    int indexD1 = index - d1;
    if (indexD1 < 0){
        indexD1 += maxBufferSize;
    }
    
    int indexD2 = index - d2;
    if (indexD2 < 0){
        indexD2 += maxBufferSize;
    }
    
    y= x + g1 * delayBuffer[indexD1][channel] + g2 * delayBuffer[indexD2][channel];
    
    delayBuffer[index][channel] = x;
    if (index <= maxBufferSize - 2){
        index++;
    }
    else{
        index = 0;
    }
}

void Delay::setFs(int Fs){
    if (Fs == 44100 || Fs == 48000 || Fs == 88200 || Fs == 96000 || Fs == 192000){
        this ->Fs = Fs;
    }
};

float Delay::getFs(){
    return Fs;
};

void Delay::setDelayTime(float d){
    
};

float Delay::getDelayTime(){
    return delay;
};

void Delay::setModAmp(float m){
    
};

float Delay::getModAmp(){
    return modAmp;
};

void Delay::setFreqLFO(float f){
    
};
float Delay::getFreqLFO(){
    return freqLFO;
};
float Delay::sinSynth(float angle) {
    
    return sinf(angle);
}
float lfo(){
    float signal = 0.0f; // variable for a sample of the signal
    float offset = 0.0f;
    
    float currentAngle = 0.0f;
    float angleChange = 0.0f;
    
    signal = modAmp * sinSynth(currentAngle) + offset;
    
}
