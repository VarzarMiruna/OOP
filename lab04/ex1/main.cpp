#include "Sort.h"
#include <iostream>

int main() {
   
    Sort randomSort(7, 77, 777);
    randomSort.Print();

    Sort listSort = { 21, 20, 17, 16 };
    listSort.InsertSort(true);
    listSort.Print();

    int arr[] = { 23, 21, 13, 11, 10 };
    Sort arraySort(arr, 5);
    arraySort.BubbleSort(true);
    arraySort.Print();

    Sort variadicSort(5, 10, 20, 30, 40, 50);
    variadicSort.Print();

    /*Sort stringSort("10,40,100,5,70");
    stringSort.Print();*/

    system("pause");
    return 0;
}
