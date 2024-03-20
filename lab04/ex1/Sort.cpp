#include "Sort.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdarg>

using namespace std;

Sort::Sort(int count, int min, int max) : length(count) {
    this->vector = new int[count];
    for (int i = 0; i < count; ++i) {
        this->vector[i] = min + rand() % (max - min + 1);
    }
}

Sort::Sort(std::initializer_list<int> list) : length(list.size()) {
    this->vector = new int[length];
    int i = 0;
    for (auto val : list) {
        vector[i++] = val;
    }
}

Sort::Sort(int* vec, int count) : vector(new int[count]), length(count) {
    for (int i = 0; i < count; i++) {
        vector[i] = vec[i];
    }
}

Sort::Sort(int count, ...) : length(count) {
    this->vector = new int[count];
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        this->vector[i] = va_arg(args, int);
    }
    va_end(args);
}


void Sort::InsertSort(bool ascendent) {
	if (ascendent)
	{
		for (int i = 1; i < length; i++)
		{
			int j = i;
			int element = vector[i];
			while (j > 0 && element > vector[j - 1])
			{
				vector[j] = vector[j - 1];
				j--;
			}
			vector[j] = element;
		}
	}
	else
	{
		for (int i = 1; i < length; i++)
		{
			int j = i;
			int element = vector[i];
			while (j > 0 && element < vector[j - 1])
			{
				vector[j] = vector[j - 1];
				j--;
			}
			vector[j] = element;
		}
	}

}
//void Sort::QuickSort(bool ascendent) {}

void Sort::BubbleSort(bool ascendent) {
	bool swapped;
	for (int i = 0; i < length - 1; i++) {
		swapped = false;
		for (int j = 0; j < length - i - 1; j++) {
			bool needSwap = false;
			if (ascendent) {
				if (vector[j] > vector[j + 1]) {
					needSwap = true;
				}
			}
			else {
				if (vector[j] < vector[j + 1]) {
					needSwap = true;
				}
			}

			if (needSwap) {
				swap(vector[j], vector[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

void Sort::Print() {
	for (int i = 0; i < length; i++)
		cout << vector[i] << " ";
	//cout << std::endl;
}
int  Sort::GetElementsCount() {
	return this->length;

}
int  Sort::GetElementFromIndex(int index) {
	if (index >= 0 && index < length) {
		return vector[index];
	}
	else
		cout << "eroare" << endl;
	return -1;
}

Sort::~Sort() {
    delete[] vector;
}

