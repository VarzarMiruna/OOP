#pragma once
#include "Car.h"
class RangeRover :
    public Car
{
    const char* name = "RangeRover";
    double FuelCapacity();
    double FuelConsumption();
    double AverageSpeed(Weather weather);
    double Range();
    void SetName(char* name);

};
