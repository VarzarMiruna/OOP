#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdio.h>     
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>

int Math::Add(int nr1, int nr2) {
	return nr1 + nr2;
}
int Math::Add(int nr1, int nr2, int nr3) {
	return nr1 + nr2 + nr3;
}
int Math::Add(double nr1, double nr2) {
	return nr1 + nr2;
}
int Math::Add(double nr1, double nr2, double nr3) {
	return nr1 + nr2 + nr3;
}
int Math::Mul(int nr1, int nr2) {
	return nr1 * nr2;
}
int Math::Mul(int nr1, int nr2, int nr3) {
	return nr1 * nr2 * nr3;
}
int Math::Mul(double nr1, double nr2) {
	return nr1 * nr2;
}
int Math::Mul(double nr1, double nr2, double nr3) {
	return nr1 * nr2 * nr3;
}
int Math::Add(int count, ...) {
	/*va_list ap;
	va_start(ap, count);
	int sum = va_arg(ap, int);
	for (int i = 1; i < count; i++)
	{
		int a = va_arg(ap, int);
		sum = sum + a;
	}
	va_end(ap);
	return sum;*/
	int s = 0;
	int* p = &count;
	p++;
	for (int i = 0; i < count; i++)
	{
		s = s + *p;
		p++;
	}
	return s;
}
char* Math::Add(const char* sir1, const char* sir2) {
	if (sir1 == nullptr || sir2 == nullptr) return nullptr;
	char* result = (char*)malloc(strlen(sir1) + strlen(sir2) + 1);
	strcpy(result, sir1);
	strcpy(result, sir2);
	return result;
}

