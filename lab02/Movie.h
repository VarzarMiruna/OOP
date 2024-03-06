#pragma once
#include <string.h>
#include <iostream>

class Movie
{
	char name[256];
	int year;
	double score; //1 and 10
	int length;
public:
	void set_name(char* name);
	char* get_name();

	void set_year(int y);
	int get_year();

	void set_score(int i);
	double get_score();

	void set_length(int l);
	int get_length();

	int get_passed_years();
	
};


//compare
static int movie_compare_name(Movie& m1, Movie& m2) {
	int ok = std::strcmp(m1.get_name(), m2.get_name());
	if (ok < 0) {
		return -1;
	}
	else if (ok > 0) {
		return 1;
	}
	else
		return 0;
}
static int movie_compare_year(Movie& m1, Movie& m2) {
	if (m1.get_year() < m2.get_year()) {
		return -1;
	}
	else if (m1.get_year() > m2.get_year()) {
		return 1;
	}
	else
		return 0;
}
static int movie_compare_score(Movie& m1, Movie& m2) {
	if (m1.get_score() < m2.get_score()) {
		return -1;
	}
	else if (m1.get_score() > m2.get_score()) {
		return 1;
	}
	else
		return 0;
}
static int movie_compare_length(Movie& m1, Movie& m2) {
	if (m1.get_length() < m2.get_length()) {
		return -1;
	}
	else if (m1.get_length() > m2.get_length()) {
		return 1;
	}
	else
		return 0;
}

static int movie_compare_passed_years(Movie& m1, Movie& m2) {
	if (m1.get_passed_years() < m2.get_passed_years()) {
		return -1;
	}
	else if (m1.get_passed_years() > m2.get_passed_years()) {
		return 1;
	}
	else
		return 0;
}