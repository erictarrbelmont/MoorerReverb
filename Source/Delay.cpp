
/*
 ==============================================================================
 
 Delay.cpp
 Created: 4 Apr 2019 1:28:00pm
 Author:  Mary Lindsey
 
 ==============================================================================
 */

#include "Delay.h"
#include <math.h>
float Delay::processSample(float x, int channel){
    float y = 0;
    
    float lfo = amp * sinf(currentAngle[channel]) + offset;
    updateAngle(channel);
    
    float d1 = floorf(delay + lfo);
    float d2 = d1 + 1.0f;
    float g2 = delay + lfo - d1;
    float g1 = 1.0f - g2;
    
    int indexD1 = index[channel] - d1;
    if (indexD1 < 0){
        indexD1 += maxBufferSize;
    }
    
    int indexD2 = index[channel] - d2;
    if (indexD2 < 0){
        indexD2 += maxBufferSize;
    }
    
    y= g1 * delayBuffer[indexD1][channel] + g2 * delayBuffer[indexD2][channel];
    
    delayBuffer[index[channel]][channel] = x;
    if (index[channel] <= maxBufferSize - 2){
            index[channel]++;
    }
    else{
        index[channel] = 0;
    }
    return y; 
}

void Delay::setFs(int Fs){
    if (Fs == 44100 || Fs == 48000 || Fs == 88200 || Fs == 96000 || Fs == 192000){
        this ->Fs = Fs;
    }
};

float Delay::getFs(){
    return Fs;
};

void Delay::setDelaySamples(float d){
    if (d <= maxBufferSize || d >= 0.0f){
        delay = d;
    }
};

float Delay::getDelaySamples(){
    return delay;
};

void Delay::setModAmp(float m){
    if (m <= 10.0f || m >= 0.0f){
        amp = m;
        offset = amp+1;
    }
};

float Delay::getModAmp(){
    return amp;
};

void Delay::setFreqLFO(float f){
    if (f >= 0.1f || f <= 5){
        angleChange = 2 * M_PI * f/Fs;
        freqLFO = f;
    }
};

float Delay::getFreqLFO(){
    return freqLFO;
};

void Delay::updateAngle(int channel){
    currentAngle[channel] += angleChange;
    if (currentAngle[channel] > 2 * M_PI){
        currentAngle[channel] -= (2*M_PI);
    }
}

