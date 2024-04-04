#include "RangeRover.h"
#include <cstring>

double RangeRover::FuelCapacity()
{
    return 90;
}

double RangeRover::FuelConsumption()
{
    return 12;
}

double RangeRover::AverageSpeed(Weather weather)
{
    switch (weather)
    {
    case Weather::Rain:
        return 90;

    case Weather::Sunny:
        return 100;

    case Weather::Snow:
        return 70;
    }

    return 0;
}

double RangeRover::Range()
{
    return FuelCapacity() / FuelConsumption();
}
void RangeRover::SetName(char* name)
{
    this->name = name;
}