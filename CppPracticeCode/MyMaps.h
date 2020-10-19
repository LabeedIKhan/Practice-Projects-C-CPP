#pragma once
#include <string>
#include <map>
#include <iostream>

using namespace std;

class MyMaps
{
	
private:

	string strarray[8] = { "Strawberry",   "Raspberry",   "Apple",  "Grapes",  "Coconut",  "Mango",  "Apricot",  "Melon" };

	//string strarray[8] = { "Labeed",   "Areeb",         "Jalees",  "Faiz",  "Saroosh",  "Nofi",  "Taymoor",  "Saman", };

	string strname[8] = { "L", "A","J","F","S","N","T", "S" };
		
	int intarray[8] = { 5, 4, 7, 6, 0, 3, 4, 6 };

	map <int, int> mapii;

	map < int, string> mapistr;

	map <string, string> mapstrstr;

public:

	MyMaps();

	void MapInsert();

	void InsretValueToOtherMap();

	void RemoveZerosKeys(map<int, int> mapii2);

	void MapInsertStr();

	void InserValuetoAnotherStrMaps();

	void RemoveValueFromStrMaps(map<string, string> mapstrstr2);

	void MapInsertIntStr();

	void InsertValuesToAnotherIntStrMap();

	void RemoveValuesfromIntStrMap(map<int, string> mapistr2);
		
};

