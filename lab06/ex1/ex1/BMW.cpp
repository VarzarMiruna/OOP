#include "BMW.h"
#include <cstring>
#include <iostream>

double BMW::FuelCapacity()
{
    return 60;
}

double BMW::FuelConsumption()
{
    return 12;
}

double BMW::AverageSpeed(Weather weather)
{
    switch (weather)
    {
    case Weather::Rain:
        return 120;

    case Weather::Sunny:
        return 140;

    case Weather::Snow:
        return 80;
    }

    return 0;
}

double BMW::Range()
{
    return FuelCapacity() / FuelConsumption();
}


void BMW::SetName(char* name)
{
    this->name = name;
}

