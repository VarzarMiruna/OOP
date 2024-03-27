#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
class Number
{
private:
	int baza = 10, valoare;
	int charToInt(char c); //char to int
	char intToChar(int num); //int to char
	void strev(char* str); //reverse la result



public:
	Number(const char* value, int base); // where base is between 2 and 16

	Number(const Number& d);
	Number(const int charToInt);
	Number(const char* str);

	friend Number operator+ (Number lhs, Number rhs);
	friend Number operator- (Number lhs, Number rhs);

	bool  operator== (const Number& n);
	bool  operator> (const Number& n);
	bool  operator< (const Number& n);
	bool  operator<= (const Number& n);
	bool  operator>= (const Number& n);
	bool  operator!= (const Number& n);

	bool  operator! () const;

	Number operator-- (int); //post
	Number& operator--(); //pre

	int operator[] (int index);
	void operator+= (Number i);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

