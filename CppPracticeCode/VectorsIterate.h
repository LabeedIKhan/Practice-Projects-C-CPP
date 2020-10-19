#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <map>

using namespace std;


class VectorsIterate
{
private:
	vector<string> vec;

	map<int, string> maps;

public:

	VectorsIterate();

	~VectorsIterate();

	void RunAndIterateVector();

	void RunAndIterateMap();

	void VectorForTuples();

	void VectorReverseIteration();

	void RunVectorOfVectors();

	void RunPairs();
};

