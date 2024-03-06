#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#include "Student.h"
#include "Compare.h"

int main() {
	Student s1;
	Student s2;

	s1.setName((char*)"Miruna");
	s1.setGradeMath(10);
	s1.setGradeEng(10);
	s1.setGradeHis(10);

	s2.setName((char*)"Abel");
	s2.setGradeMath(10);
	s2.setGradeEng(8);
	s2.setGradeHis(9);

	std::cout << "Name: "<< s1.getName()<< ", " <<"Grade math: " << s1.getGradeMath()<< ", "<< "english: " << s1.getGradeEng() << ", " << "history: " << ", " << s1.getGradeHis() << ", " << "average: " << s1.getAverage() << std::endl;
	std::cout << "Name: " << s2.getName() << ", " << "Grade math: " << s2.getGradeMath() << ", " << "english: " << s2.getGradeEng() << ", " << "history: " << ", " << s2.getGradeHis() << ", " << "average: " << s2.getAverage() << std::endl;

	/*printf("Name: %s, grade math: %d, english: %d, history: %d, average: %d\n", s1.getName(), s1.getGradeMath(), s1.getGradeEng(), s1.getGradeHis(), s1.getAverage());
	printf("Name: %s, grade math: %d, english: %d, history: %d, average: %d\n", s2.getName(), s2.getGradeMath(), s2.getGradeEng(), s2.getGradeHis(), s2.getAverage());
	*/


	Student s3;// pt primul constructor
	//printf("Name: %s, grade math: %d, english: %d, history: %d\n", s3.getName(), s3.getGradeMath(), s3.getGradeEng(), s3.getGradeHis(), s3.getAverage());
	std::cout << "Name: " << s3.getName() << ", " << "Grade math: " << s3.getGradeMath() << ", " << "english: " << s3.getGradeEng() << ", " << "history: " << ", " << s3.getGradeHis() << ", " << "average: " << s3.getAverage() << std::endl;

	Student s4((char*)"Miru", 7, 7, 7); //pt al doilea constructor
	//printf("Name: %s, grade math: %d, english: %d, history: %d\n", s4.getName(), s4.getGradeMath(), s4.getGradeEng(), s4.getGradeHis(), s4.getAverage());
	std::cout << "Name: " << s4.getName() << ", " << "Grade math: " << s4.getGradeMath() << ", " << "english: " << s4.getGradeEng() << ", " << "history: " << ", " << s4.getGradeHis() << ", " << "average: " << s4.getAverage() << std::endl;


	std::cout << "Compare: " << std::endl;
	int nameCmp = Compare::compareName(s1, s2);
	std::cout << "Name: " << nameCmp<<std::endl;
	int mathCmp = Compare::compareMath(s1, s2);
	std::cout << "Math grade: " << mathCmp << std::endl;
	int engCmp = Compare::compareEng(s1, s2);
	std::cout << "English grade: " <<engCmp << std::endl;
	int hisCmp = Compare::compareHis(s1, s2);
	std::cout << "History grade: " << hisCmp << std::endl;
	int averageCmp = Compare::compareAverage(s1, s2);
	std::cout << "Average grade: " << averageCmp << std::endl;
	system("pause");
	return 0;
}