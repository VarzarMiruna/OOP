#pragma once
#include "Student.h"

class Compare
{
public:
	static int compareName(Student&s1, Student&s2);
	static int compareMath(Student& s1, Student& s2);
	static int compareEng(Student& s1, Student& s2);
	static int compareHis(Student& s1, Student& s2);
	static int compareAverage(Student& s1, Student& s2);
};

