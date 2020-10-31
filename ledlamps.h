#ifndef LEDLAMPS_H
#define LEDLAMPS_H
#include "lamps.h"

class LEDLamps:public Lamps
{
public:
    LEDLamps(const int powerLED=0, const int intensityRed=0, const int intensityGreen=0, const int intensityBlue=0);
    LEDLamps(const LEDLamps &lamp);
    void output() const;
    int getPowerLED() const;
    int getIntensityRed() const;
    int getIntensityGreen() const;
    int getIntensityBlue() const;
    void setPowerLED(const int power);
    void setIntensityRed(const int intensityRed);
    void setIntensityGreen(const int intensityGreen);
    void setIntensityBlue(const int intensityBlue);
private:
    int intensityRed, intensityGreen, intensityBlue, powerLED;
};

#endif // LEDLAMPS_H
