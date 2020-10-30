#pragma once

#include <string>
#include <iostream>

using namespace std;

template<typename T>
struct Node{
	T elem;
	struct Node<T>* previous = nullptr;
	struct Node<T>* next = nullptr;

	~Node();
};

template<typename T>
inline Node<T>::~Node()
{
	previous = nullptr;
	next = nullptr;
}


template<typename T>
class LinkedList {

private:
	struct Node<T>* start;
	struct Node<T>* end;
	int size;

public:
	LinkedList();

	~LinkedList();

	void AddElements(T toadd);

	void AddElementAt(T elem, int i);

	void RemoveElement(T rem);

	void RemoveAt(int i);

	T& GetElementAt(int i);

	int& Size();

	int IndexOf(T elem);
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
	this->start = nullptr;
	this->end = nullptr;
	this->size = 0;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	/**
	Node<T>* startnode = this->start;
	Node<T>* current = startnode;

	while (current != nullptr)
	{
		Node<T>* temp = current;
		cout << "Deleting " << endl;
		current->elem.PrintDetails();
		delete current;
		current = temp->next;
		system("pause");
	}*/
	//delete this->end;
}

template<typename T>
inline void LinkedList<T>::AddElements(T toadd)
{
	cout << " Adding " << endl;
	if (this->size == 0)
	{
		Node<T>* node = new Node<T>;

		node->elem = toadd;

		this->start = node;

		this->end = node;

		node->previous = nullptr;

		node->next = nullptr;

		this->size++;

	}
	else
	{
		Node<T>* current = this->start;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		Node<T>* newnode = new Node<T>;

		newnode->elem = toadd;

		current->next = newnode;

		newnode->previous = current;

		this->end = newnode;

		this->size++;
	}
}

template<typename T>
inline void LinkedList<T>::AddElementAt(T elem, int i)
{
	if ((i < this->Size()) && (i >= 0))
	{
		if (i == 0)
		{
			Node<T>* current = this->start;

			Node<T>* newnode = new Node<T>();

			newnode->elem = elem;

			newnode->previous = nullptr;

			newnode->next = current;

			this->start = newnode;

			this->size++;

		}
		else if (i == this->size - 1)
		{
			AddElements(elem);
		}
		else
		{
			Node<T>* current = this->start;

			while (this->IndexOf(current->elem) != i - 1)
			{
				current = current->next;
			}

			Node<T>* succ = current->next;

			Node<T>* newnode = new Node<T>();

			newnode->elem = elem;

			current->next = newnode;

			newnode->previous = current;

			succ->previous = newnode;

			newnode->next = succ;

			this->size++;

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
	Node<T>* current = this->start;

	while (current->elem != rem)
	{
		current = current->next;
	}

	Node<T>* prev = current->previous;

	Node<T>* succ = current->next;

	current->next = nullptr;

	current->previous = nullptr;

	delete current;

	prev->next = succ;

	succ->previous = prev;

	this->end = succ;

	this->size--;
}

template<typename T>
inline void LinkedList<T>::RemoveAt(int i)
{

	if ((i < this->size) && (i >= 0))
	{
		if (i == 0)
		{
			Node<T>* current = this->start;

			Node<T> * newstart = current->next;

			newstart->previous = nullptr;

			current->previous = nullptr;

			current->next = nullptr;

			this->start = newstart;

			delete current;

			this->size--;


		}
		else if (i == this->size - 1)
		{
			Node<T>* current = this->start;

			while (this->IndexOf(current->elem) != i)
			{
				current = current->next;
			}

			Node<T>* newlast = current->previous;

			current->previous = nullptr;

			newlast->next = nullptr;

			current->next = nullptr;

			this->end = newlast;

			delete current;

			this->size--;
			
		}
		else
		{
			
			Node<T>* current = this->start;


			this->size--;

			int index = 0;

			while (index != i )
			{
				current = current->next;
				index++;
			}
			
			Node<T>* prev = current->previous;
			Node<T>* succ = current->next;

			current->previous = nullptr;
			current->next = nullptr;

			prev->next = succ;
			succ->previous = prev;

			while (succ->next != nullptr)
			{
				succ = succ->next;
			}
			this->end = succ;

			current = nullptr;
			delete current;

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
	Node<T>* current = this->start;

	if ((i < this->size) && (i >= 0))
	{
		if (i == 0)
		{
			return current->elem;
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
inline int& LinkedList<T>::Size()
{
	return this->size;
}

template<typename T>
inline int LinkedList<T>::IndexOf(T elem)
{
	Node<T>* current = this->start;
	int index = 0;
	while (current->elem != elem)
	{
		index++;
		current = current->next;
	}

	return index;
}

