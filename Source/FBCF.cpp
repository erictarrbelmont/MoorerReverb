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
    float FBCF::processSample(float x,int channel);
    
    //y(n)=x(n)-g*y(n - delay) use this for difference equation for FBCF
    
    
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
            if (g >= 0.1f){
                gain = g;
            }
        }
        
    };
    
    
    float FBCF::getGain(){
        
        return gain;
    };
    
    
    void FBCF::getDelayLength(); //get delay from somewhere
    
    
    float FBCF::setDelayLength(float d);
    
    delay=d;
    
    
private:
    
    
    
    

  
    
    
};


#endif
