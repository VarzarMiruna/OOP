#pragma once
#include "Car.h"
class Volvo :
    public Car
{
    const char* name = "Volvo";

    double FuelCapacity();
    double FuelConsumption();
    double AverageSpeed(Weather weather);
    double Range();
    void SetName(char* name);

};