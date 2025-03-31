#include "AcousticWave.h"
#include <iostream>
int main() {
    AcousticWave w{5,2,4};
    AcousticWave w2;

    std::cout << w2.getFrequency() << " " << w.getFrequency() << '\n';

    std::cout << w.getNumberOfSamples();
    return 0;
}