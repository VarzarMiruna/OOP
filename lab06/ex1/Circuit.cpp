#include "Circuit.h"
#include <iostream>
#include "Weather.h"

using namespace std;

Circuit::Circuit() : length(0), weather(Sunny), cars(), nrCars(0)  //constructor
{
    for (int i = 0; i < 7; ++i) {
        cars[i] = nullptr; // Initialize the cars array
        race[i].name = nullptr; // Initialize the race array names
        race[i].time = 0; // Initialize the race array times
    }
}
Circuit:: ~Circuit() //destrutor to free memory
{
    for (int i = 0; i < nrCars; i++)
    {
        delete cars[i];
        delete[] race[i].name;
    }
    delete[] cars;
    
}

void Circuit::SetLength(int length)
{
    this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
    this->weather = weather;
}

void Circuit::AddCar(Car* car)// Add a car to the list of cars participating
{
   cars[nrCars++] = car;
      
}

void Circuit::Race()
{
    for (int i = 0; i < nrCars; i++)
    {
        if (cars[i]->Range() >= length)
        {
            cars[i]->SetName(race[i].name);
            race[i].time = length / cars[i]->AverageSpeed(weather);
        }
        else
        {
            cars[i]->SetName(race[i].name);
            race[i].time = -1;
        }

        for (int i = 0; i < nrCars - 1; i++)
        {
            for (int j = i + 1; j < nrCars; j++)
                if (race[i].time < race[j].time)
                {
                    car aux = race[i];
                    race[i] = race[j];
                    race[j] = aux;
                }
        }

    }
}

    void Circuit::ShowFinalRanks() {
        std::cout << "Final ranks:" << std::endl;
        for (int i = 0; i < nrCars; ++i) {
            if (race[i].time != -1) {
                std::cout << race[i].name << ": " << race[i].time << " minutes" << std::endl;
            }
        }
    }


    void Circuit::ShowWhoDidNotFinish() {
        std::cout << "Cars that did not finish:" << std::endl;
        for (int i = 0; i < nrCars; ++i) {
            if (race[i].time == -1) {
                std::cout << race[i].name << std::endl;
            }
        }
    }