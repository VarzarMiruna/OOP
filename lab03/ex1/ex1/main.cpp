#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Math.h"
using namespace std;

int main() {
	Math d;
	printf("Suma a 2 nr intregi: %d\n", d.Add(1, 2));
	printf("Suma a 3 nr intregi: %d\n", d.Add(1, 2, 3));
	printf("Suma a 2 nr double: %d\n", d.Add(1.5, 2.5));
	printf("Suma a 3 nr double: %d\n", d.Add(1.5, 2.5, 1.5));

	printf("Produsul a 2 nr intregi: %d\n", d.Mul(1, 9));
	printf("Produsul a 3 nr intregi: %d\n", d.Mul(1, 9, 2));
	printf("Produsul a 2 nr double: %d\n", d.Mul(1.5, 1.5, 2.5));
	printf("Produsul a 3 nr double: %d\n", d.Add(5, 1, 2, 3, 4, 5));


	system("pause");
	return 0;
}
