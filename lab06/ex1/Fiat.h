#pragma once
#include "Car.h"
class Fiat :
    public Car
{
    const char* name = "Fiat";
    double FuelCapacity();
    double FuelConsumption();
    double AverageSpeed(Weather weather);
    double Range();
    void SetName(char* name);

};
