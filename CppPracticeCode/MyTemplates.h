#pragma once

#include <iostream>
#include <string>
#include <memory.h>
#include <memory>
#include <vector>
using namespace std;

template<typename T>
class Maths
{
public:
	
	T GetMinimum(const T& x, const T& y);
};


template<typename T>
inline T Maths<T>::GetMinimum(const T& x, const T& y)
{
	return x < y ? x : y;
}

class MyTemplates {

public:
	void RunMaths();
	void RunTemplateExcercises();
};


class ClassMin {

public:
	int number;
	string description;

	bool operator < (ClassMin y);
};


template<typename T, size_t L>
class MyArray {

	T array[L];
public:
	MyArray(){}
};

template<typename T>
class SimpleArray {

private:
	int capacity;
	int size;
	T * array;

public:
	SimpleArray();
	SimpleArray(int capacity);
	~SimpleArray();
	int Getsize();
	void Add(T elem);
	T& GetIndex(int index);
};

template<typename T>
SimpleArray<T>::SimpleArray()
{
}

template<typename T>
SimpleArray<T>::SimpleArray(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->array = new T[this->capacity];
}

template<typename T>
SimpleArray<T>::~SimpleArray()
{
	delete[] this->array;
}

template<typename T>
int SimpleArray<T>::Getsize() 
{
	return this->size;
}

template<typename T>
void SimpleArray<T>::Add(T elem)
{
	if (this->size < this->capacity)
	{
		this->array[this->size++] = elem;
	} else {
		cout << "Array Is Full" << endl;
	}
}

template<typename T>
T& SimpleArray<T>::GetIndex(int index)
{
	if (index < 0 || index >= this->size)
	{
		throw "Index Out Of Bound Exception";
	}

	return array[index];
}


struct isPrivate {

private:
	string name;

public:
	isPrivate(){}
};
