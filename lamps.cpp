#include "lamps.h"
#include <iostream>
#include "ledlamps.h"
using namespace std;
Lamps::Lamps(const int powers, const int intensities) {
    setPower(powers);
    setIntensity(intensities);
};

Lamps::Lamps(const Lamps &lamps) {
    setPower(lamps.getPower());
    setIntensity(lamps.getIntensity());
};
int Lamps::getPower() const {
    return power;
};

int Lamps::getIntensity() const {
    return intensity;
};
int Lamps::getIntensityRed() const {
    return intensityRed;
};
int Lamps::getIntensityGreen() const {
    return intensityGreen;
};
int Lamps::getIntensityBlue() const {
    return intensityBlue;
};

void Lamps::setPower(const int powers) {
    if (powers <= 0)
        power = 0;
    else if (powers >= 200)
        power = 200;
    else
        power = powers;
};

void Lamps::setIntensity(const int intensities) {
    if (intensities <= 0)
        intensity = 0;
    else if (intensities >= 500)
        intensity = 500;
    else
        intensity = intensities;
};
void Lamps::output() const {
    cout << "Power: " << power << endl;
    cout << "Intensity: " << intensity << endl;
};
