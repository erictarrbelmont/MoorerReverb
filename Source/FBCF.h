//
//  FBCF.hpp
//  MoorerReverb - AU
//
//  Created by Mark Blackham on 4/4/19.
//

#ifndef FBCF_h
#define FBCF_h

#include <stdio.h>
#include "Delay.h"

class FBCF {

    public:

        float processSample(float x,int channel);

        void setFs(float Fs);
        float getFs();

        void setGain(float ampdB);//float input needs to come from process block
        float getGain();

        void setDelaySamples(int d); //get delay from somewhere
        int getDelaySamples();

        void setRate(float r);
        float getRate();

        void setDepth(float depth);
        float getDepth();


    private:
    int Fs = 48000;
    Delay delay;
    float delayTime = 1.0f;
    float gain = 0.7f;
    float y1[2]={0.0f};
    float rate = 1.0f;
    float depth = 1.0f;
    int maxBufferSize = 960000;
    
};

#endif /* FBCF_hpp */
