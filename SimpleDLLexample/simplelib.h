#pragma once
#include <string>
#include <memory>
#include <memory.h>
#include <vector>
#include <fstream>

using namespace std;

#ifdef ReuLib_EXPORTS
#define ReuLib_API __declspec(dllexport)
#else
#define ReuLib_API __declspec(dllimport)
#endif


extern "C++" ReuLib_API int GetDelimiterOccurence(string str, char delimiter);

extern "C++" ReuLib_API shared_ptr<string[]> GetStringFromString(string str, string delimitor);

extern "C++" ReuLib_API string GetFileText(string filename);

extern "C++" ReuLib_API void WriteToFile(string filename, string data);

extern "C++" ReuLib_API bool FileExist(string filename);