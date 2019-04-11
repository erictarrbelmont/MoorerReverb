//
//  FBCF.hpp
//  MoorerReverb - AU
//
//  Created by Mark Blackham on 4/4/19.
//

#ifndef FBCF_h
#define FBCF_h

#include <stdio.h>


public:

float processSample(float x,int channel);

void setFs(float Fs);
float getFs();

void setGain(float ampdB);//float input needs to come from process block
float getGain();

void getDelayLength(); //get delay from somewhere
float setDelayLength();


private:

float delay = 1.0f;
float gain = 0.7f;
#endif /* FBCF_hpp */
