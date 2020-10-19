#include "Queue.h"

Queue::Queue()
{
	cout << "\n" << "Queue Starts Here" << endl;
	cout << "\n" << "=================" << endl;
	InsertInStrQueue();
	InsertInIntQueue();
	InsertInDoubleQueue();
}

void Queue::InsertInStrQueue()
{
	
	for (auto str : sarray)
	{
		qstr.push(str);
	}
 
	cout << "\n" << qstr.size() << endl;

	AddStringQueueToSet(qstr);

	while (!qstr.empty())
	{
		cout << "\n" << qstr.front();
		qstr.pop();
	}

	cout << "\n" << qstr.size() << endl;
	
}

void Queue::AddStringQueueToSet(queue<string> thestrqueue)
{
	set<string> myset;

	while (!thestrqueue.empty())
	{
		myset.insert(thestrqueue.front());
		thestrqueue.pop();
	}

	set<string>::iterator itr;

	cout << "\n" << "After adding Queue to Set" << endl;

	for (itr = myset.begin(); itr != myset.end(); itr++)
	{
		cout << *itr << endl;
	}

	cout << "\n";

}

void Queue::InsertInIntQueue()
{
	for (auto in : iarray)
	{
		ique.push(in);
	}

	cout << "\n" << "Size of Queue " << ique.size() << endl;

	cout << "\n" << "Front of Queue " << ique.front() << endl;

	while (!ique.empty())
	{
		cout << ique.front() << endl;

		ique.pop();
	}
}



void Queue::InsertInDoubleQueue()
{
	for (auto doub : darray)
	{
		dque.push(doub);
	}

	PrintInsertInDoubleQueue(dque);

	//PrintInsertInDoubleByDeque(dque);

	cout << "\n" << "Size After print Method" << endl;

	cout << "\n" << "Size of Queue " << dque.size() << endl;

	PrintInsertInDoubleQueue(dque);

	cout << "\n" << "Front of Queue " << dque.front() << endl;

}

void Queue::PrintInsertInDoubleQueue(queue<double> dqu)
{
	cout << "\n" << "Print Double Que" << endl;

	while (!dqu.empty())
	{
		cout << dqu.front() << endl;
		dqu.pop();
	}
	cout << "\n";
}

void Queue::PrintInsertInDoubleByDeque(deque<double> bydeque)
{
	deque<double>::iterator itr;

	cout << "\n" << "Print By Deque" << endl;

	for (itr = bydeque.begin(); itr != bydeque.end(); itr++)
	{
		cout << *itr << endl;
	}
}
