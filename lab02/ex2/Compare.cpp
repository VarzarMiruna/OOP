#include "Compare.h"
#include <cstring>
#include <iostream>

int Compare::compareName(Student& s1, Student& s2) {
	int ok= std::strcmp(s1.getName(), s2.getName());
	if (ok < 0) {
		return 1;
	}
	else if (ok > 0) {
		return -1;
	}
	else
		return 0;
}

int Compare::compareMath(Student& s1, Student& s2) {
	if (s1.getGradeMath() > s2.getGradeMath()) {
		return 1;
	}
	else if (s1.getGradeMath() < s2.getGradeMath()) {
		return -1;
	}
	else
		return 0;
}

int Compare::compareEng(Student& s1, Student& s2) {
	if (s1.getGradeEng() > s2.getGradeEng()) {
		return 1;
	}
	else if (s1.getGradeEng() < s2.getGradeEng()) {
		return -1;
	}
	else
		return 0;
}

int Compare::compareHis(Student& s1, Student& s2) {
	if (s1.getGradeHis() > s2.getGradeHis()) {
		return 1;
	}
	else if (s1.getGradeHis() < s2.getGradeHis()) {
		return -1;
	}
	else
		return 0;
}

int Compare::compareAverage(Student& s1, Student& s2) {
	if (s1.getAverage() > s2.getAverage()) {
		return 1;
	}
	else if (s1.getAverage() < s2.getAverage()) {
		return -1;
	}
	else
		return 0;
}