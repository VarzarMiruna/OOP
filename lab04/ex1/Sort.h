#pragma once


#include <initializer_list>

class Sort {
    int* vector;
    int length;
public:
    Sort(int count, int min, int max); 
    Sort(std::initializer_list<int> list);
    Sort(int* vec, int count);

    Sort(int count, ...); 
    //Sort(const char* string); 
    ~Sort(); 

    void InsertSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};



