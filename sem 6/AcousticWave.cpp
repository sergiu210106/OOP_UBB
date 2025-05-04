#include "AcousticWave.h"

void AcousticWave::computeSamples(float _freq, float _sampleRate, float _duration) {
    this->numberOfSamples = _sampleRate * _duration;
    this->samples = new float[this->numberOfSamples]();
}

AcousticWave::~AcousticWave() {
    delete[] this->samples;
}

AcousticWave::AcousticWave(const AcousticWave& other) {
    this->frequency = other.frequency;
    this->amplitude = other.amplitude;
    this->sampleRate = other.sampleRate;
    this->numberOfSamples = other.numberOfSamples;
    
    this->samples = new float[this->numberOfSamples];
    for (int i = 0; i < this->numberOfSamples; i ++) {
        this->samples[i] = other.samples[i];
    }
}

