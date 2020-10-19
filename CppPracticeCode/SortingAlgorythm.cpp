#include "SortingAlgorythm.h"
#include <vector>

SortingAlgorytm::SortingAlgorytm()
{
	SimpleSort();

	SortDescend();

	PrintArrayBefore();

	PrintArrayAfter();

	IndexException();

	ArraySort();
}

SortingAlgorytm::~SortingAlgorytm()
{
}

void SortingAlgorytm::SimpleSort()
{
	//int n = sizeof(myArray)/ sizeof(myArray[0]);

	int n = *(&myArray + 1) - myArray;

	PrintArrayBefore();

	sort(myArray, myArray+n);

	PrintArrayAfter();
}

void SortingAlgorytm::SortDescend()
{
	//int n = sizeof(myArray)/ sizeof(myArray[0]);

	int n = *(&myArray + 1) - myArray;

	PrintArrayBefore();

	sort(myArray, myArray + n, greater<int>());

	PrintArrayAfter();
}

void SortingAlgorytm::PrintArrayBefore()
{

	cout << "Before sorting " << endl;

	for (int i = 0; i < sizeof(myArray) / sizeof(myArray[0]); i++)
	{
		cout << myArray[i] << " ";
	}

	cout << "\n";
}

void SortingAlgorytm::PrintArrayAfter()
{
	cout << "After sorting " << endl;

	for (int i = 0; i < sizeof(myArray) / sizeof(myArray[0]); i++)
	{
		cout << myArray[i] << " ";
	}
	cout << "\n";
}

void SortingAlgorytm::IndexException()
{
}

void SortingAlgorytm::ArraySort()
{
	int size = 0;
	int range;

	Again:

	cout << "\n";
	cout << "Please enter size of Array" << "\n";

	cin >> size;

	cout << "\n";
	cout << "Please enter range of Array" << "\n";

	cin >> range;

	if (size > 10000)
	{
		cout << "To big Size " << endl;
		goto Again;
	}
	

	int* ranlist = new int[size];

	cout << size << endl;

	for (int i = 0; i < size; i++)
	{
		int n = 1 + (rand() % range);
		ranlist[i] = n;
	}

	cout << "For Array 1 not Sorted" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << ranlist[i] <<  " ";
	}

	cout << "\n Array1 Unsorted End\n" << endl;

	BubbleSort(ranlist, size);

	int* ranlist1 = new int[size];

	cout << size << endl;

	for (int i = 0; i < size; i++)
	{
		int n = 1 + (rand() % range);
		ranlist1[i] = n;
	}

	cout << "For Array 2 not Sorted" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << ranlist1[i] << " ";
	}

	cout << "\n" << endl;

	QuickSort(ranlist1, size);

	delete[] ranlist;

	delete[] ranlist1;
	
	cout << "\n End =============== End" << endl;
}

void SortingAlgorytm::BubbleSort(int * arr, int size)
{
	bool anyChanged;

	int counter = 0;

	do
	{
		anyChanged = false;

		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				anyChanged = true;
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				counter++;
			}
		}

	} while (anyChanged);

	cout << "Array 1 Sorted Array " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\nThe Counter is" << endl;
	cout << counter << endl;
}

void SortingAlgorytm::QuickSort(int * arr, int size)
{
	cout << "Array 2 Sorted Array " << endl;

	int counter = 0;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\nThe Counter is" << endl;
	cout << counter << endl;
}




shared_ptr<string[]> SortingAlgorytm::GetStringFromstring(string str, string delimitor)
{
	string sample = str;

	int pos = 0;

	string delimiter = delimitor;
	string token;

	vector<string> vec;

	while ((pos = sample.find(delimiter)) != string::npos)
	{
		token = sample.substr(0, pos);
		//cout << token << endl;
		vec.push_back(token);
		sample.erase(0, pos + delimiter.length());
	}

	vec.push_back(sample);

	shared_ptr<string[]> list(new string[vec.size()]);

	for (int i = 0; i < vec.size(); i++)
	{
		list[i] = vec.at(i);
	}
	return list;
}


int SortingAlgorytm::GetDelimiterOccurence(string str,string delimiter)
{
	int i = 0;

	for (int j = 0; j < str.length(); j++)
	{
		if (to_string(str[j]) == delimiter)
			i++;
	}

	return i;
}

