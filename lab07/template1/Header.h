#pragma once
#include <iostream>
#include <cstdlib>


// Each node in the tree will contain a value of type T (the template type) and a list of children

/*add_node method (to add new node to the tree). The method will receive the parent node or nullptr
get_node method (returns a reference / method to a node). The method receives a pointer/reference to its parent (if the reference is nullptr,
than the root node will be returned).

delete_node method (deletes a node and all its children)

find method --> recursively search all nodes for a parameter. The method will receive a pointer to a function that
will compare the parameter received to the value T from each node. Thre method returns the first occurence.

insert method (insert an new node in a tree at a specific index, given its parent note.)
sort method (sort all children from a specific node ==> use a callback function to provide a way to compare two elements. If the callback function is not present (nullptr), operator< is used.)
count method (returns how many children a node has). This method walks recursively through all children. If call with nullptr, it returns the count of all children from the root of the tree*/

template<class T>
class Tablou
{
private:
	T* array = nullptr;
	int size; // elemente
	int realsize; // memorie alocata 

	int intialsize = 2;
	int multiplicator = 2; // multiplicator
public:
	Tablou();
	~Tablou();
	void add_node(const T& item);
	//void add_node(const T& item);//T& Pop(); 
	void Delete(int pos);//deletes a node and all its children
	T& get_node(int index);
	void Insert(const T& value, int index);//insert an new node in a tree at a specific index, given its parent note.
	int Count();//returns how many children a node has
	void Sort(int (*cmp)(const T& a, const  T& b) = nullptr); //sort all children from a specific node ==> use a callback function 
	int first(T element, int (*egal)(const T& a, const T& b) = nullptr); //compare the parameter received to the value T from each node

	void print();

};

template<class T>
int Tablou<T>::first(T element, int  (*egal)(const T& a, const T& b))
{

	if (egal == nullptr)
	{
		for (int i = 0; i < size; i++)
			if (array[i] == element)
				return i;
	}
	else
	{

		for (int i = 0; i < size; i++)
			if (egal(array[i], element))
				return i;
	}
}

template<class T>
void Tablou<T>::Sort(int  (*cmp) (const T& a, const T& b))
{
	int temp;

	if (cmp == nullptr)
	{
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
			{
				if ((array[i] > array[j]))
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
	}
	else
	{

		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
			{
				if (cmp(array[i], array[j]))
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
	}
}

template<class T>
void Tablou<T>::Insert(const T& val, int ind)
{
	size++;

	if (size > realsize)
	{
		realsize *= multiplicator;

		array = (T*)realloc(array, sizeof(T) * realsize);


	}


	for (int i = size; i >= ind; i--)
		array[i] = array[i - 1];

	array[ind] = val;
}


template<class T>
void Tablou<T>::print()
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << "\n";
}

template <class T>
Tablou<T>::Tablou()
{
	realsize = intialsize;
	size = 0;
	array = (T*)malloc(realsize * sizeof(T));

}

template <class T>
Tablou<T>::~Tablou()
{
	if (array)
	{
		free(array);
		array = NULL;
	}
}

template <class T>
int Tablou<T>::Count()
{
	return size;
}

template <class T>
void Tablou<T>::Delete(int pos)
{
	for (unsigned int i = pos; i < size - 1; i++)
		array[i] = array[i + 1];
	size--;
}

template <class T>
void Tablou<T>::add_node(const T& item)
{
	size++;

	if (size > realsize)
	{
		realsize *= multiplicator;

		array = (T*)realloc(array, sizeof(T) * realsize);


	}

	array[size - 1] = item;
}

template <class T>
T& Tablou<T>::get_node(int index)
{
	return array[index];
}



