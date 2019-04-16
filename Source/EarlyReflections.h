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
    
    void synthesizeIR(float IR){
        while (i < lengthIR) {
            if i == tapTimes(tapIndex){
                IR(i)[2] = tapGain(tapIndex);
            }
            tapIndex++;
            i++;
        }
        A
    }
    
    float scaleTapTimes(float Fs, int tapTimes[18){
        f = Fs / 44100.0f;
        taptimes *= f;
        tapTimes = int;
    }
    
    float processSample(float x, float y, int channel){
                                               
                                               y1 = tapGains() * buffer[index +   ]
                                               y2 =
//
//                                              delayBuffer(index) = x;
//
//                                              if (int index >= tapTimes(tapIndex)){
//                                                if (int tapIndex < 18){
//                                                    tapIndex++;
//                                                    gainIndex++;
//                                                    index = 0;
//                                                }
//                                                else tapIndex = 0;
//                                              }
//                                              index++;
//
//                                              y = y + tapGains(gainIndex) *
//
//
//
//
//
//                                              index = 0;
//                                              }

                                


private:
    float y = 0.0f;
    int delayBufferLength = 3520;
    float Fs = 48000;
    float IR[lengthIR][2] = {0.0f}
    int tapIndex = 0;
    int gainIndex = 0;
                                               
                                               
    int tapTimes[18] = [190,759,44,190,9,123,706,119,384,66,35,75,419,4,79,66,53,194];
                                               
    float tapGains[18] = [.841,.504,.49,.379,.38,.346,.289,.272,.192,.193,.217,.181,.18,.181,.176,.142,.167,.134,];

                                              
    float delayBuffer[int delayBufferLength][2] = {0.0f};
    int index = 0;
};


AudioBuffer
