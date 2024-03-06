#include "NumberList.h"
#include <iostream>
#include <algorithm>

void NumberList::Init() {
	count = 0;
}


bool NumberList::Add(int x) { // adds X to the numbers list and increase the data member count.
	// if count is bigger or equal to 10, the function will return false
	if (count < 10) {
		numbers[count++] = x;
		return true;
	}
	else
		return false;
}

void NumberList::Sort() {          // will sort the numbers vector
	//int n = sizeof(numbers) / sizeof(numbers[0]);
	std::sort(numbers, numbers + count);
}

void NumberList::Print() {      // will print the current vector
	//int n = sizeof(numbers) / sizeof(numbers[0]);
	for (int i = 0; i < count; i++)
	{
		std::cout << numbers[i];
	}

}