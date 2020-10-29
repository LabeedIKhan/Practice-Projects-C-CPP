#pragma once

#include <string>
#include <iostream>

using namespace std;

template<typename T>
class LinkedList
{
private:
	T elem;
	LinkedList<T>* previous = nullptr;
	LinkedList<T>* next = nullptr;

public:

	LinkedList();

	LinkedList(T elem);

	~LinkedList();

	void AddElements(T toadd);

	void AddElementAt(T elem, int i);

	void RemoveElement(T rem);

	void RemoveAt(int i);

	T& GetElementAt(int i);

	int Size();

	int IndexOf(T elem);

};

template<typename T>
inline LinkedList<T>::LinkedList()
{

}

template<typename T>
inline LinkedList<T>::LinkedList(T elem)
{
	this->elem = elem;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	LinkedList<T>* current = this->next;
	if (current != nullptr)
	{
		LinkedList<T>* temp = current;
		//cout << "Deleting " << current->elem << endl;
		delete current;
		current = temp->next;
	}

	//cout << "Deleeting " << this->elem;
}

template<typename T>
inline void LinkedList<T>::AddElements(T toadd)
{

	LinkedList<T>* current = this;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	LinkedList<T>* newnode = new LinkedList<T>(toadd);

	current->next = newnode;

	newnode->previous = current;

}

template<typename T>
inline void LinkedList<T>::AddElementAt(T elem, int i)
{

	if ((i < this->Size()) && (i >= 0))
	{
		if (i == 0)
		{
			//this = new LinkedList<T>();
		}
		else if (i == this->Size() - 1)
		{
			AddElements(elem);
		}
		else
		{
			LinkedList<T>* current = this;

			while (this->IndexOf(current->elem) != i - 1)
			{
				current = current->next;
			}

			LinkedList<T>* succ = current->next;

			LinkedList<T>* newnode = new LinkedList<T>(elem);

			current->next = newnode;

			newnode->previous = current;

			succ->previous = newnode;

			newnode->next = succ;

		}
	}
	else
	{
		throw invalid_argument("Index out of bound");
	}
}

template<typename T>
inline void LinkedList<T>::RemoveElement(T rem)
{
	LinkedList<T>* current = this;

	while (current->elem != rem)
	{
		current = current->next;
	}

	LinkedList<T>* prev = current->previous;

	LinkedList<T>* succ = current->next;

	current->next = nullptr;

	current->previous = nullptr;

	delete current;

	prev->next = succ;

	succ->previous = prev;


}

template<typename T>
inline void LinkedList<T>::RemoveAt(int i)
{
	LinkedList<T>* current = this;

	if ((i < this->Size()) && (i >= 0))
	{
		if (i == 0)
		{
			//this = new LinkedList<T>();
		}
		else if (i == this->Size() - 1)
		{
			while (this->IndexOf(current->elem) != i)
			{
				current = current->next;
			}

			LinkedList<T>* last = current->previous;

			last->next = nullptr;

			current->previous = nullptr;

			//current->next = nullptr;

			delete current;
		}
		else
		{

			while (this->IndexOf(current->elem) != i)
			{
				current = current->next;
			}

			LinkedList<T>* prev = current->previous;
			LinkedList<T>* succ = current->next;

			current->next = nullptr;
			current->previous = nullptr;

			delete current;

			prev->next = succ;
			succ->previous = prev;
		}
	}
	else
	{
		throw invalid_argument("Index out of bound");
	}

}

template<typename T>
inline T& LinkedList<T>::GetElementAt(int i)
{
	LinkedList<T>* current = this;

	if ((i < this->Size()) && (i >= 0))
	{
		if (i == 0)
		{
			return this->elem;
		}

		else
		{

			while (this->IndexOf(current->elem) != i)
			{
				current = current->next;
			}

			return current->elem;
		}
	}
	else
	{
		throw invalid_argument("Index out of bound");
	}
}


template<typename T>
inline int LinkedList<T>::Size()
{
	LinkedList<T>* current = this;
	int size = 0;
	while (current != nullptr)
	{
		size++;
		current = current->next;
	}
	return size;
}

template<typename T>
inline int LinkedList<T>::IndexOf(T elem)
{
	LinkedList<T>* current = this;
	int index = 0;
	while (current->elem != elem)
	{
		index++;
		current = current->next;
	}

	return index;
}


