#include "Movie.h"
#include <string.h>
#include <iostream>

void Movie::set_name(char* name) {
	strcpy_s(this->name, 256, name);
}
char* Movie::get_name() {
	return this->name;
}

void Movie::set_year(int y) {
	this->year = y;

}
int Movie::get_year() {
	return this->year;
}

void Movie::set_score(int i) {
	this->score = i;
}
double Movie:: get_score() {
	return this->score;
}

void Movie::set_length(int l) {
	this->length = l;
}

int Movie::get_length() {
	return this->length;
}

int Movie::get_passed_years() {
	return (2024 - (this->year));
}


