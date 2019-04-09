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
    float d1 = floorf(delay);
    float d2 = d1 + 1;
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
    if (d <= 10 || d >= 0.1){
        d = delay;
    }
};

float Delay::getDelayTime(){
    return delay;
};

void Delay::setModAmp(float m){
    if (modAmp <= 1.0f || modAmp >= 0.0f){
        m = modAmp;
        amp = 0.5f * modAmp;
        offset = 1.0f - amp;
    }
};

float Delay::getModAmp(){
    return modAmp;
};

void Delay::setFreqLFO(float f){
    
};
float Delay::getFreqLFO(){
    return freqLFO;
};
float Delay::sinSynth(){
    float out = sinf(currentAngle);
    updateAngle();
    return out;
};
float Delay::lfo(){
    float signal = 0.0f; // variable for a sample of the signal
    signal = amp * sinSynth() + offset;
}
void Delay::updateAngle(){
    currentAngle += angleChange;
    if (currentAngle > 2 * M_PI){
        currentAngle -= (2*M_PI);
    }
}

float Delay::getNextSample(){
        float lfo = 0.0f;
            lfo = modAmp * sinSynth() + offset;
        return lfo;
}

