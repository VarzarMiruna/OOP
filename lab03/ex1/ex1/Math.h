#pragma once
class Math
{
public:
    static int Add(int nr1, int nr2);
    static int Add(int nr1, int nr2, int nr3);
    static int Add(double nr1, double nr2);
    static int Add(double nr1, double nr2, double nr3);
    static int Mul(int nr1, int nr2);
    static int Mul(int nr1, int nr2, int nr3);
    static int Mul(double nr1, double nr2);
    static int Mul(double nr1, double nr2, double nr3);
    static int Add(int count, ...); // sums up a list of integers
    static char* Add(const char* sir1, const char* sir2); //will allocate memory that can add the two existing string. If one of the strings is nullptr, this function will return nullptr;
};

