//
//  FBCF.cpp
//  MoorerReverb - AU
//
//  Created by Mark Blackham on 4/4/19.
//

#include "FBCF.h"
class FBCF {
    
public:
    
    FBCF(){};
    ~FBCF(){};
    
    // Functions for Compressor
    float FBCF::processSample(float x,int channel){
    
    float w=x+-g*y1;
    //y(n)=x(n)-g*y(n - delay) use this for difference equation for FBCF
        //delay.processSample(w);
        y1=delay.processSample(w);
        return y1;
    }
    void FBCF::setFs(int Fs){
        // Code to check for valid sampling rate
        if (Fs == 44100 || Fs==48000 ||Fs==88200||Fs==96000||Fs==192000) {
            
            this->Fs = Fs;
            
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
    
    
    void FBCF::setDelaySamples(float d){
        if (d <= maxBufferSize || d >= 0.0f){
            delayTime = d;
            delay.setDelaySamples(d);
        }
    };
    
    float FBCF::getDelaySamples(){
        return delay;
    };
    
    void FBCF::setRate(float r){
        rate = r;
        
    }
    float FBCF::getRate(){
        return rate;
        
    }
    
    void FBCF::setDepth(float depth){
        Depth = depth;
    }
    float FBCF::getDepth(){
        return Depth;
    }
    
private:
    
    
    
    

  
    
    
};


#endif
