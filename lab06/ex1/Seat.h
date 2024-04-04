#pragma once
#include "Car.h"
class Seat :
    public Car
{
    const char* name = "Seat";
    double FuelCapacity();
    double FuelConsumption();
    double AverageSpeed(Weather weather);
    double Range();
    void SetName(char* name);

};
