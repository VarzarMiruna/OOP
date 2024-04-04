#pragma once
#include "Weather.h"

//Abstract class Car only has virtual methods (it does not need a .cpp file)

class Car
{
public:
    virtual double FuelCapacity() = 0;
    virtual double FuelConsumption() = 0;
    virtual double AverageSpeed(Weather weather) = 0;

    //virtual void SetWeather(Weather weather) = 0;
    //virtual void SetLength(double length) = 0;

    virtual void SetName(char*) = 0;
    virtual double Range() = 0;
};