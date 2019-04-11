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
    float processSample(float x,int channel);
    
    void setFs(float Fs);
    float getFs();
    
    void setGain(float ampdB);//float input needs to come from process block
    float getGain();
    
    void getDelayLength(); //get delay from somewhere
    float setDelayLength();
    
    
    //y(n)=x(n)-g*y(n - delay) use this for difference equation for FBCF
    
private:
    
    float Fs = 48000.0f; // Sampling Rate
    
    // Variables for User to Modify Filter
    float freq = 20.0f; // frequency in Hz
    float Q = 0.707f; // Q => [0.1 - 10]
    float ampdB = 0.0f;  // Amplitude on dB scale
    
    // Intermediate Variables
    float w0 = 2 * M_PI * freq/Fs; // Normalize frequency
    float alpha = sinf(w0)/(2.0f*Q); // Bandwidth/slope/resonance parameter
    float A = powf(10.0f,ampdB/40.0f); // Linear amplitude
    
    // Variables for Biquad Implementation
    // 2 channels - L,R
    float x1[2] = {0.0f}; // 1 sample of delay feedforward
    float x2[2] = {0.0f}; // 2 samples of delay feedforward
    float y1[2] = {0.0f}; // 1 sample of delay feedback
    float y2[2] = {0.0f}; // 2 samples of delay feedback
    
    // Filter coefficients
    float b0 = 1.0f; // initialized to pass signal
    float b1 = 0.0f; // without filtering
    float b2 = 0.0f;
    float a0 = 1.0f;
    float a1 = 0.0f;
    float a2 = 0.0f;
    
    void updateCoefficients();
};


#endif /* Biquad_h */
