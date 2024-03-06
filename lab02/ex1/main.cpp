#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"

int main() {
	NumberList list;

	list.Init();
	list.Add(5);
	list.Add(3);
	list.Add(1);
	list.Add(4);
	list.Add(2);
	list.Print();
	std::cout << " \n";
	list.Sort();
	list.Print();
	
	return 0;
}