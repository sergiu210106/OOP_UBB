#pragma once
class AcousticWave {
    protected:
        float frequency{10};
        float amplitude{2};
        float sampleRate{1000};
        float* samples{nullptr};
        unsigned int numberOfSamples{15};

    public:
        AcousticWave() = default;
        AcousticWave(float _freq, float _ampl, float _sampleRate) : frequency{_freq}, amplitude{_ampl}, sampleRate{_sampleRate} {}
        // this is faster than implementing in .cpp {frequency = _freq...}
        // attributes have to be in the order
        // a default constructor is created if there is not another implemented constructor

        float getFrequency() const {
            return this->frequency;
        }
        
        unsigned int getNumberOfSamples() const {
            return this->numberOfSamples;
        }

        float* getSamples() const {
            return this->samples;
        }

        void computeSamples(float _freq, float _sampleRate, float _duration); // duration in seconds

        ~AcousticWave();

        AcousticWave(const AcousticWave& other);

        AcousticWave& operator=(const AcousticWave& other) {
            if (this != &other) {
                this->frequency = other.frequency;
                this->amplitude = other.amplitude;
                this->sampleRate = other.sampleRate;
                this->numberOfSamples = other.numberOfSamples;

                delete[] this->samples;
                
                this->samples = new float[this->numberOfSamples];
                for (int i = 0; i < this->numberOfSamples; i ++) {
                    this->samples[i] = other.samples[i];
                }
            }
            return *this;
        }
    };