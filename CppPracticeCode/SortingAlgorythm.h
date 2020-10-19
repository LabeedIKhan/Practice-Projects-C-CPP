#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class SortingAlgorytm
{
private:

	
	int myArray[7] = { 5, 8, 9, 7, 2, 1, -3};

public:

	SortingAlgorytm();

	~SortingAlgorytm();

	void SimpleSort();

	void SortDescend();

	void PrintArrayBefore();

	void PrintArrayAfter();

	void IndexException();

	void ArraySort();

	void BubbleSort(int * arr, int size);
	// Not Implemented
	void QuickSort(int * arr, int size);

	shared_ptr<string[]> GetStringFromstring(string str, string delimiter);

	int GetDelimiterOccurence(string str, string delimiter);

};

