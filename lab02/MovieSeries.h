#pragma once
class MovieSeries
{
	int movies[16];
	int count;

public:
    void init();          
    bool add();      
    void sort();     
    void print();
};

