#include<iostream>
//din Fahrenheit in Celsius => °C = (°F − 32) ÷ 1,8
//din kelvin	in Celsius => °C = K − 273,15

float operator""_Kelvin(unsigned long long int k)
{
	return k - 273.15;
}
float operator""_Fahrenheit(unsigned long long int f)
{
	return (f - 32) / 1.8;
}

int main()
{
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	std::cout << a << "\n" << b<< std::endl;
	return 0;
}