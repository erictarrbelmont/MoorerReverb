//
//  FBCF.cpp
//  MoorerReverb - AU
//
//  Created by Mark Blackham on 4/4/19.
//

#include "FBCF.h"

    
    // Functions for Compressor
    float FBCF::processSample(float x,int channel){
    
    float w=x+ (-gain)*y1[channel];
    //y(n)=x(n)-g*y(n - delay) use this for difference equation for FBCF
        //delay.processSample(w);
        y1[channel]=delay.processSample(w,channel);
        return y1[channel];
    }

    void FBCF::setFs(float Fs){
        // Code to check for valid sampling rate
        if (Fs == 44100 || Fs==48000 ||Fs==88200||Fs==96000||Fs==192000) {
            
            this->Fs = Fs;
            delay.setFs(Fs);
        }
    }
    
    
    
    float FBCF::getFs(){
        return Fs;
    };
    
    void FBCF::setGain(float g){
        // Code to check that "d" is valid for drive
        if (g < 1.0f) {
            if (g >= 0.0f){
                gain = g;
            }
        }
    };
    
    
    float FBCF::getGain(){
        
        return gain;
    };
    
    
    void FBCF::setDelaySamples(int d){
        if (d <= maxBufferSize || d >= 0.0f){
            delayTime = d;
            delay.setDelaySamples(d);
        }
    };
    
    int FBCF::getDelaySamples(){
        return delayTime;
    };
    
    void FBCF::setRate(float r){
        rate = r;
        delay.setFreqLFO(rate);
    };
    float FBCF::getRate(){
        return rate;
    };
    
    void FBCF::setDepth(float depth){
      this->depth = depth;
        delay.setModAmp(depth);
        
    }
    float FBCF::getDepth(){
        return depth;
    }
