//
//  main.cpp
//  EarlyReflections
//
//  Created by Victor Pacek on 4/4/19.
//  Copyright © 2019 Victor Pacek. All rights reserved.
//

#include <iostream>
#include math.h

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
    
    float scaleTapTimes(float Fs,int tapTimes[18){
                                          f = Fs / 48000.0f;
                                          taptimes *= f;
    }
    
    float processSample(float x, int channel){
                                              float y = 0.0f;
                                              index++;
                                              if (index >= delayBufferLength){
                                              
                                              }
//                                              y = sum of scaled taps
                                


private:
    int delayBufferLength = 3520;
    float Fs = 48000;
    int tapTimes[18] = [190,759,44,190,9,123,706,119,384,66,35,75,419,4,79,66,53,194];
    float tapGains[18] = [.841,.504,.49,.379,.38,.346,.289,.272,.192,.193,.217,.181,.18,.181,.176,.142,.167,.134,];

                                              
                                              float delayBuffer[int delayBufferLength][2] = {0.0f};
                                              int index = 0;
};
