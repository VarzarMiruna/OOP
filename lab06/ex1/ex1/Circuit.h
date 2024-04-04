#pragma once
#include "Car.h"
#include "Weather.h"
#include <cstring>
#include <vector>

class Circuit
{
public:
    Circuit();
    ~Circuit();
    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();

    void ShowFinalRanks();
    void ShowWhoDidNotFinish();


private:

    //void ShowFinalRanks();
    //void ShowWhoDidNotFinish();

    int length;
    Weather weather;
    Car* cars[7];
    int nrCars;

    struct car
    {
        char* name;
        int time;
    }race[7];

};