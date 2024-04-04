#include "Seat.h"
#include <cstring>

double Seat::FuelCapacity()
{
    return 60;
}

double Seat::FuelConsumption()
{
    return 8;
}

double Seat::AverageSpeed(Weather weather)
{
    switch (weather)
    {
    case Weather::Rain:
        return 90;

    case Weather::Sunny:
        return 110;

    case Weather::Snow:
        return 70;
    }
    return 0;
}

double Seat::Range()
{
    return FuelCapacity() / FuelConsumption();
}

void Seat::SetName(char* name)
{
    this->name = name;
}

