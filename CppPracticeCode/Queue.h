#pragma once
#include <string>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

class Queue
{
private:

	queue <string>  qstr;

	queue <int>  ique;

	queue <double>  dque;

	string sarray[8] = { "Person1",   "Person2",   "Person3",  "Person4",  "Person5",  "Person6",  "Person7",  "Person8", };

	int iarray[8] = { 5, 4, 7, 6, 0, 3, 4, 6 };

	double darray[8] = { 3.5, 7.4, 5.7, 10.6, 11.0, 3.6, 4.1, 6.7 };

public:

	Queue();

	void InsertInStrQueue();

	void InsertInIntQueue();

	void AddStringQueueToSet(queue<string> thestrqueue);

	void InsertInDoubleQueue();

	void PrintInsertInDoubleQueue(queue<double> dqu);

	void PrintInsertInDoubleByDeque(deque<double> bydeque);
};

