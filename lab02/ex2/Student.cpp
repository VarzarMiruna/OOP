#include "Student.h"
#include <string.h>
#include <iostream>

Student::Student() {
	memset(this->name, 0, 10);
	this->gradeMath = 0;
	this->gradeEng = 0;
	this->gradeHis = 0;
}

Student::Student(char* name, int gradeMath, int gradeEng, int gradeHis) {
	strcpy_s(this->name, 10, name);
	this->gradeMath = gradeMath;
	this->gradeEng = gradeEng;
	this->gradeHis = gradeHis;
}
Student::~Student() {
	memset(this->name, 0, 10);
	this->gradeMath = 0;
	this->gradeEng = 0;
	this->gradeHis = 0;
}

void Student::setName(char* name) {
	strcpy_s(this->name, 10, name);
}

char* Student::getName() {
	return this->name;
}

void Student::setGradeMath(int m) {
	this->gradeMath = m;
}

int Student::getGradeMath() {
	return this->gradeMath;
}

void Student::setGradeEng(int e) {
	this->gradeEng = e;
}

int Student::getGradeEng() {
	return this->gradeEng;
}

void Student::setGradeHis(int h) {
	this->gradeHis = h;
}

int Student::getGradeHis() {
	return this->gradeHis;
}

/*void Student::setAverage(int a) {
	this->average = a;
}*/

int Student::getAverage() {
	return (gradeMath + gradeEng + gradeHis) / 3;
}

