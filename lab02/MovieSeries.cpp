#include "MovieSeries.h"
#include <iostream>
#include <algorithm>

void MovieSeries::init() {
	count = 0;
}
bool MovieSeries::add() {

}
void MovieSeries::sort() {
	std::sort(movies, movies + count);
}
void MovieSeries::print() {
	for (int i = 0; i < count; i++)
	{
		std::cout << movies[i];
	}
}