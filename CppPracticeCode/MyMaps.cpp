#include "MyMaps.h"


MyMaps::MyMaps()
{
	MapInsert();
	MapInsertStr();
	MapInsertIntStr();
}

void MyMaps::MapInsert()
{
	for (int i = 0; i < sizeof(intarray) / sizeof(intarray[0]); i++)
	{
		mapii.insert(pair<int, int>(i, intarray[i]));
	}
	 
	cout << "print Separate values by key " << endl;

	cout << mapii.find(4)->first << "   " << mapii.find(4)->second << "\n" << endl;

	map<int, int>::iterator intitr;

	cout << "Itrerate over values" << endl;

	for (intitr = mapii.begin(); intitr != mapii.end(); intitr++)
	{
		cout << intitr->first << "   " << intitr->second << " " << endl;
	}
	cout << "\n";
	InsretValueToOtherMap();
}

void MyMaps::InsretValueToOtherMap()
{
	map<int, int> mapii2;

	mapii.insert(pair<int, int>(-1, 9));

	mapii.insert(pair<int, int>(-2, 4));

	mapii2.insert(mapii.begin(), mapii.end());

	cout << "Itrerate over values to another map" << endl;

	map<int, int>::iterator intitr;

	for (intitr = mapii2.begin(); intitr != mapii2.end(); intitr++)
	{
		cout << intitr->first << "   " << intitr->second << " " << endl;
	}
	cout << "\n";

	RemoveZerosKeys(mapii2);
}

void MyMaps::RemoveZerosKeys(map<int,int> mapii2)
{
	cout << "Remove Key below zero value" << endl;

	map<int, int>::iterator intitr;

	mapii2.erase(mapii2.begin(), mapii2.find(0));

	for (intitr = mapii2.begin(); intitr != mapii2.end(); intitr++)
	{
		cout << intitr->first << "   " << intitr->second << " " << endl;
	}

	mapii2.erase(3);
	 
	cout << "\n" << " Erase key 3 value" << "\n";

	for (intitr = mapii2.begin(); intitr != mapii2.end(); intitr++)
	{
		cout << intitr->first << "   " << intitr->second << " " << endl;
	}

	cout << "\n" << "Find elements up and below 6" << "\n";

	cout << mapii2.upper_bound(6)->first << "\n";
	cout << mapii2.lower_bound(6)->first << "\n";

	cout << "Now Again add 3 key and it value" << "\n";

	mapii2.insert(pair<int, int>(3, 6));

	for (intitr = mapii2.begin(); intitr != mapii2.end(); intitr++)
	{
		cout << intitr->first << "   " << intitr->second << " " << endl;
	}


	cout << "\n";

	
}

void MyMaps::MapInsertStr()
{
	for (int i = 0; i < sizeof(strarray) / sizeof(strarray[0]); i++)
	{
		mapstrstr.insert(pair<string, string>(strname[i], strarray[i]));
	}

	map<string, string>::iterator itr;

	cout << "\n" << "Inserted String values in Str array" << endl;

	for (itr = mapstrstr.begin(); itr != mapstrstr.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << "\n";
	}

	cout << "\n";
	InserValuetoAnotherStrMaps();
}


void MyMaps::InserValuetoAnotherStrMaps()
{

	map<string, string> mapstrstr2;

	mapstrstr2.insert(pair<string, string>("P1", "Person1"));
	mapstrstr2.insert(pair<string, string>("P2", "Person2"));

	mapstrstr2.insert(mapstrstr.begin(), mapstrstr.end());

	map<string, string>::iterator itr;

	cout << "\n" << "After Adding another maps" << endl;

	for (itr = mapstrstr2.begin(); itr != mapstrstr2.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << "\n";
	}

	cout << "\n";
	RemoveValueFromStrMaps(mapstrstr2);
}

void MyMaps::RemoveValueFromStrMaps(map<string, string> mapstrstr2)
{
	cout << "\n" << "Remove Value by Key for Str Array" << endl;

	mapstrstr2.erase("P1");

	map<string, string>::iterator itr;

	cout << "\n" << "After Removing Some Values by key" << endl;

	for (itr = mapstrstr2.begin(); itr != mapstrstr2.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << "\n";
	}

	cout << "\n";

	string val;

	for (itr = mapstrstr2.begin(); itr != mapstrstr2.end(); itr++)
	{
		if (itr->second == "Mango")
		{
			val = itr->first;
		}
	}
	
	mapstrstr2.erase(val);

	cout << "\n" << "After Removing Some Values by Value" << endl;

	for (itr = mapstrstr2.begin(); itr != mapstrstr2.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << "\n";
	}
	
	cout << "\n";
}

void MyMaps::MapInsertIntStr()
{
	for (int i = 0; i < sizeof(intarray) / sizeof(intarray[0]); i++)
	{
		mapistr.insert(pair<int, string>(i, strarray[i]));
	}

	cout << "\n" << "Print int key and str values" << endl;

	map<int, string>::iterator itr;

	for (itr = mapistr.begin(); itr != mapistr.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << endl;
	}

	InsertValuesToAnotherIntStrMap();
}

void MyMaps::InsertValuesToAnotherIntStrMap()
{
	mapistr.insert(pair<int, string>(8, "Person11"));

	cout << "\n" << "Print After Adding new values" << endl;

	map<int, string>::iterator itr;

	for (itr = mapistr.begin(); itr != mapistr.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << endl;
	}
	cout << "\n";

	map<int, string> mapistr2;

	mapistr2.insert(pair<int, string>(9, "Person12"));

	mapistr2.insert(mapistr.begin(), mapistr.end());
	 
	cout << "\n" << "After adding to another array" << endl;

	for (itr = mapistr2.begin(); itr != mapistr2.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << endl;
	}
	cout << "\n";

	RemoveValuesfromIntStrMap(mapistr2);
}

void MyMaps::RemoveValuesfromIntStrMap(map<int, string> mapistr2)
{
	mapistr2.erase(9);

	map<int, string>::iterator itr;

	cout << "\n" << "Print After removing value" << "\n";

	for (itr = mapistr2.begin(); itr != mapistr2.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << endl;
	}
	cout << "\n";

	int val;

	for (itr = mapistr2.begin(); itr != mapistr2.end(); itr++)
	{
		if (itr->second == "Mango")
		{
			val = itr->first;
		}
	}

	mapistr2.erase(val);

	cout << "\n" << "Print After removing another value" << "\n";

	for (itr = mapistr2.begin(); itr != mapistr2.end(); itr++)
	{
		cout << itr->first << "  " << itr->second << endl;
	}
	cout << "\n";
}

