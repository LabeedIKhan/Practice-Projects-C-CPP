#include "MyTemplates.h"






void MyTemplates::RunMaths()
{
	shared_ptr<Maths<int>> maths = make_shared<Maths<int>>();

	int min = maths->GetMinimum(6, 8);

	cout << min << endl;

	shared_ptr<Maths<char>> mathschar = make_shared<Maths<char>>();

	char minchar = mathschar->GetMinimum('A', 'B');

	cout << minchar << endl;

	ClassMin cmin1 { 1 ,"One" };
	ClassMin cmin2{ 0, "Two" };

	cout << (cmin1 < cmin2) << endl;


}

void RunArray()
{
	MyArray<int, 10> myarr();

	SimpleArray<int> sarr;
	SimpleArray<string> sarrstr(5);

	for (int i = 0; i < 5; i++)
	{
		sarrstr.Add("Hello + " + to_string(i));
	}

	for (int i = 0; i < 5; i++)
	{
		cout << sarrstr.GetIndex(i) << endl;
	}

}

void MyTemplates::RunTemplateExcercises()
{
	RunMaths();
	RunArray();
}

bool ClassMin::operator<(ClassMin y)
{
	ClassMin minc;

	if (this->number < y.number)
	{
		return true;
	}
	else
	{
		return false;
	}
}


