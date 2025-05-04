#pragma once
#include "AcousticWave.h"
#include <math.h>
class SineWave : public AcousticWave {
    public: 
        SineWave(float _freq, float _amplitude, float _sampleRate): AcousticWave{_freq, _amplitude, _sampleRate} {};
        void computeSamples(float _freq, float _sampleRate, float _duration) {
            AcousticWave::computeSamples(_freq, _sampleRate, _duration);
            float step = 1 / this->sampleRate;
            for (int i = 0; i < this->numberOfSamples; i ++) {
                this->samples[i] = this->amplitude * sin(2 * M_PI * this->frequency * i * step);
            }
        }
};