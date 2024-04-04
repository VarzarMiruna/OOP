#include "Volvo.h"
#include <cstring>

double Volvo::FuelCapacity()
{
    return 60; //litres 
}

double Volvo::FuelConsumption()
{
    return 6; // litres per 100 km
}

double Volvo::AverageSpeed(Weather weather)
{
    switch (weather) //return km/h
    {
    case Weather::Rain:
        return 80;

    case Weather::Sunny:
        return 100;

    case Weather::Snow:
        return 60;
    }

    return 0;
}

double Volvo::Range()
{
    return FuelCapacity() / FuelConsumption();
}

void Volvo::SetName(char* name)
{
    this->name = name;
}

