/*
  ==============================================================================

    Delay.cpp
    Created: 4 Apr 2019 1:28:00pm
    Author:  Mary Lindsey

  ==============================================================================
*/

#include "Delay.h"
#include <math.h>



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
