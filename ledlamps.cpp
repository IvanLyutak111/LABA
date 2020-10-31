#include "ledlamps.h"
#include "iostream"
using namespace std;

LEDLamps::LEDLamps(const int powerLEDs, const int intensitiesRed,const int intensitiesGreen, const int intensitiesBlue )
{
    setPowerLED(powerLEDs);
    setIntensityRed(intensitiesRed);
    setIntensityGreen(intensitiesGreen);
    setIntensityBlue(intensitiesBlue);
}
LEDLamps::LEDLamps(const LEDLamps &lamps):Lamps(lamps) {
    setPowerLED(lamps.getPower());
    setIntensityRed(lamps.getIntensityRed());
    setIntensityGreen(lamps.getIntensityGreen());
    setIntensityBlue(lamps.getIntensityBlue());
};
int LEDLamps::getPowerLED() const {
    return powerLED;
};

int LEDLamps::getIntensityRed() const {
    return intensityRed;
};
int LEDLamps::getIntensityGreen() const {
    return intensityGreen;
};
int LEDLamps::getIntensityBlue() const {
    return intensityBlue;
};
void LEDLamps::setPowerLED(const int powers) {
    if (powers <= 0)
        powerLED = 0;
    else if (powers >= 200)
        powerLED = 200;
    else
        powerLED = powers;
};

void LEDLamps::setIntensityRed(const int intensities) {
    if (intensities <= 0)
        intensityRed = 0;
    else if (intensities >= 500)
        intensityRed = 500;
    else
        intensityRed = intensities;
};
void LEDLamps::setIntensityGreen(const int intensities) {
    if (intensities <= 0)
        intensityGreen = 0;
    else if (intensities >= 500)
        intensityGreen = 500;
    else
        intensityGreen = intensities;
};
void LEDLamps::setIntensityBlue(const int intensities) {
    if (intensities <= 0)
        intensityBlue = 0;
    else if (intensities >= 500)
        intensityBlue = 500;
    else
        intensityBlue = intensities;
};
void LEDLamps::output() const {
    cout << "Power: " << powerLED << endl;
    cout << "IntensityRed: " << intensityRed << endl;
    cout << "IntensityGreen: " << intensityGreen << endl;
    cout << "IntensityBlue: " << intensityBlue << endl;
};
