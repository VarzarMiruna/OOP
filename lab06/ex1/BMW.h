#pragma once
#include "Car.h"
class BMW :
    public Car
{
    const char* name = "BMW";

    double FuelCapacity();
    double FuelConsumption();
    double AverageSpeed(Weather weather);
    double Range();
    void SetName(char* name);

    //void SetWeather(Weather weather);
    //void SetLength(double length);

};
