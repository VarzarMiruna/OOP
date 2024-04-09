#include "Header.h" 
#include <iostream> 

using namespace std;

int cmp(const int& a, const int& b)
{
	if (a > b) { return 1; }
	else return 0;
}

int egal(const int& a, const int& b)
{
	if (a == b) { return 1; }
	else return 0;
}

int main()
{
	Tablou<int> s;
	s.add_node(3);
	s.add_node(2);
	s.add_node(4);
	s.add_node(20);
	s.add_node(5);
	printf("arborele");
	s.print();

	printf("Am folosit Get, elementul este: %d  \n ", s.get_node(3));
	printf("Count, avem: %d copii \n", s.Count());

	s.Insert(22, 4);
	s.print();
	s.Delete(4);
	s.print();
	s.Sort(cmp);
	s.print();
	printf("Metoda first: %d \n", s.first(14, egal));

	return 0;
}
