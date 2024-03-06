#pragma once
class Student
{
	char name[10];
	int gradeMath;
	int gradeEng;
	int gradeHis;
	//int average;
public:
	Student();
	Student(char* name, int gradeMath, int gradeEng, int gradeHis);
	~Student();

	void setName(char* name); //char name[10];
	char* getName();

	void setGradeMath(int m);
	int getGradeMath();

	void setGradeEng(int e);
	int getGradeEng();

	void setGradeHis(int h);
	int getGradeHis();

	//void setAverage(int a);
	int getAverage();
};

