#include "Fiat.h"
#include <cstring>

double Fiat::FuelCapacity()
{
    return 60;
}

double Fiat::FuelConsumption()
{
    return 7;
}

double Fiat::AverageSpeed(Weather weather)
{
    switch (weather)
    {
    case Weather::Rain:
        return 80;

    case Weather::Sunny:
        return 90;

    case Weather::Snow:
        return 70;
    }

    return 0;
}

double Fiat::Range()
{
    return FuelCapacity() / FuelConsumption();
}

void Fiat::SetName(char* name)
{
    this->name = name;
}
