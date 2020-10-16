

#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "simplelib.h"





 int GetDelimiterOccurence(string str, char delimiter)
{
	 int i = 0;

	 for (char c : str)
	 {
		 if (c == delimiter)
			 i++;
	 }

	 return i + 1;
}


 string GetFileText(string filename)
 {

	 string text = "";

	 ifstream file;
	 try
	 {
		 string line;
		 file = ifstream(filename);

		 while (getline(file, line))
		 {
			 text += line;
		 }

		 file.close();
		 return text;
	 }

	 catch (exception e)
	 {
		 file.close();
		 return "";
	 }


 }


 void WriteToFile(string filename, string data)
 {
	 ofstream writeto;
	 try
	 {
		 writeto.open(filename, ios_base::app);
		 writeto << data;
	 }
	 catch (exception e)
	 {
		 writeto.close();
	 }
 }

 bool FileExist(string filename)
 {

	 ifstream file;

	 try
	 {
		 file = ifstream(filename);
		 file.close();
		 return file.good();
	 }
	 catch (exception e)
	 {
		 try
		 {
			 file.close();
			 return false;
		 }
		 catch (exception e)
		 {
			 return false;
		 }
		 return false;
	 }
 }

 template<typename T>
 shared_ptr<T[]> JoinArrays(shared_ptr<T[]> arr1, int len1, shared_ptr<T[]> arr2, int len2)
 {
	 shared_ptr<T[]> arr3(new T[len1 + len2]);

	 for (int i = 0; i < len1; i++)
	 {
		 arr3[i] = arr1[i];
	 }

	 for (int i = 0; i < len2; i++)
	 {
		 arr3[i + len1] = arr2[i];
	 }

	 return arr3;
 }

 
 shared_ptr<string[]> GetStringFromString(string str, string delimitor)
 {

	 int pos = 0;

	 string token;

	 vector<string> vec;

	 while ((pos = str.find(delimitor)) != string::npos)
	 {
		 token = str.substr(0, pos);
		 vec.push_back(token);
		 str.erase(0, pos + delimitor.length());
	 }

	 vec.push_back(str);

	 shared_ptr<string[]> list(new string[vec.size()]);

	 for (int i = 0; i < vec.size(); i++)
	 {
		 list[i] = vec.at(i);
	 }
	 return list;
 }