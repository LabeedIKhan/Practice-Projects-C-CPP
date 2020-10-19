#include "VectorsIterate.h"
#include <iostream>



VectorsIterate::VectorsIterate()
{
	RunAndIterateVector();

	RunAndIterateMap();

	VectorForTuples();

	VectorReverseIteration();

	RunVectorOfVectors();

	RunPairs();
}

VectorsIterate::~VectorsIterate()
{
}

void VectorsIterate::RunAndIterateVector()
{
	for (int i = 0; i < 50; i++)
	{
		vec.push_back("Vec Number : "+ to_string(i));
	}

	vector<string>::reverse_iterator it;

	for (it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << endl;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}


}

void VectorsIterate::RunAndIterateMap()
{
	for (int i = 0; i < 50; i++) {

		maps.insert({ i, "Number is " + to_string(i) });
	}

	map<int, string>::reverse_iterator rit;

	for (rit = maps.rbegin(); rit != maps.rend(); rit++)
	{
		cout << rit->first << " " << rit->second << endl;
	}
}

void VectorsIterate::VectorForTuples()
{
	vector<tuple<int, string>> vec;


	for (int i = 0; i < 50; i++)
	{
		tuple<int, string>  tu;

		tu = make_tuple(i, "Tuple Number is " + to_string(i));

		vec.push_back(tu);
	}

	vector<tuple<int, string>>::reverse_iterator it;

	for (it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << get<0>(*it) << " " << get<1>(*it) << endl;
	}

}

void VectorsIterate::VectorReverseIteration()
{
	vector<string> vec;

	for (int i = 0; i < 50; i++)
	{
		vec.push_back("Vec RevNUmber is " + to_string(i));
	}

	/**
	vector<string>::iterator it;

	for (it = vec.end(); it != vec.begin(); --it)
	{
		cout << *it << endl;
	}
	*/
}

void VectorsIterate::RunVectorOfVectors()
{
	cout << "\nVector of Vector Run Start \n";

	vector<vector<string>> vecy;

	for (int i = 0; i < 10; i++)
	{
		vector<string> vecx;

		for (int j = 0; j < 10; j++)
		{
			vecx.push_back(to_string(j) + " ");
		}

		vecy.push_back(vecx);
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << vecy[i][j];
		}

		cout << "\n";
	}


	cout << "\nVector of Vector Run By Iterator Start \n";

	vector<vector<string>>::iterator ity;

	vector<string>::iterator itx;

	for (ity = vecy.begin(); ity != vecy.end(); ity++)
	{
		for (itx = (*ity).begin(); itx != (*ity).end(); itx++)
		{
			cout << *itx;
		}

		cout << "\n";
	}

	cout << "\nVector of Vector Run By Iterator End \n";

	cout << "\nVector of Vector Run End \n";

}

void VectorsIterate::RunPairs()
{

	cout << "\nPairs Routine Starts Here\n";

	pair<int, char> pai;

	pai.first = 100;
	pai.second = 'A';

	cout << pai.first << " " << pai.second << endl;

	pai.first = 200;
	pai.second = 'B';

	cout << pai.first << " " << pai.second << endl;

	pair<int, char> pair1(300, 'C');

	cout << pair1.first << " " << pair1.second << endl;

	pair<int, char> pair2 = make_pair(500, 'M');

	cout << pair2.first << " " << pair2.second << endl;
	 
	cout << "\nSwap Pairs" << endl;

	swap(pair1, pair2);

	cout << pair1.first << " " << pair1.second << endl;

	swap(pai, pair1);

	cout << pai.first << " " << pai.second << endl;

	cout << "\nComparison Starts Here\n";

	pair<int, int> num_pair1(3, 8);

	pair<int, int> num_pair2(4, 8);

	pair<int, int> num_pair3(3, 8);

	cout << (num_pair1 == num_pair2) << endl;

	cout << (num_pair1 == num_pair3) << endl;

	cout << "\nComparison Ends Here\n";

	cout << "\nPairs Routine Ends Here\n";
}
