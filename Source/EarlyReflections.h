//
//  main.cpp
//  EarlyReflections
//
//  Created by Victor Pacek on 4/4/19.
//  Copyright © 2019 Victor Pacek. All rights reserved.
//

#include <iostream>
#include <math.h>




class EarlyReflections {
    
  
public:
    void setFs(){
        if (Fs == 44100||Fs == 48000||Fs == 88200||Fs == 96000||Fs == 192000){
        this->Fs = Fs;
        }
    }
        
    float getFs(){
        return Fs;
    }
    
    // Call on PrepareToPlay to scale delay tap timestamps
    void scaleTapTimes(float Fs, int tapTimes[18]){
        f = Fs / 44100.0f;
        for (int n = 0; n < 18; ++n){;
            tapTimes[n] *= f;
        }
    }
    
    float processSample(float x, int channel){
       delayBuffer[index][channel] = x;
       for (int n = 0; n < 18; ++n){
           y += tapGains[n] * delayBuffer[index + tapTimes[n]][channel];
            if (n >= 18){
                n = 0;
            }
           ++index;
        }
       return y;
    }
                                       
    
private:
    float f = 1.0f;
    float y = 0.0f;
    int delayBufferLength = 3520;
    float Fs = 48000;
    int tapIndex = 0;
    int gainIndex = 0;
                                               
                                               
    int tapTimes[18] = {190,949,993,1183,1192,1315,2021,2140,2524,2590,2625,2700,3119,3123,3202,3268,3321,3515};
                                               
    float tapGains[18] = {.841,.504,.49,.379,.38,.346,.289,.272,.192,.193,.217,.181,.18,.181,.176,.142,.167,.134};

                                              
    int delayBuffer[3520][2] = {0};
    int index = 0;
};



