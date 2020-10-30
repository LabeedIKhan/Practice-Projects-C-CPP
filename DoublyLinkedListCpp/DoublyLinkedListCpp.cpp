#include "LinkedList.h"

class Person {

public:

	string name;
	int age;

public:
	Person();
	Person(string name, int age) : name(name), age(age) {}
	~Person();
	bool operator ==(Person p2);
	bool operator !=(Person p2);
	void PrintDetails();
	string Tostring();
};

Person::Person()
{
}

Person::~Person()
{
}

bool Person::operator==(Person p2)
{
	if ((this->name.compare(p2.name) == 0) && (this->age == p2.age))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Person::operator!=(Person p2)
{
	if ((this->name.compare(p2.name) == 0) && (this->age == p2.age))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Person::PrintDetails()
{
	cout << "The Name is " << this->name << " The age is " << this->age << endl;
}

string Person::Tostring()
{
	return "The Name is " + this->name + " The age is " + to_string(this->age);
}


int main()
{

	Person p0("Person0", 10);
	Person p1("Person1", 11);
	Person p2("Person2", 12);
	Person p3("Person3", 13);
	Person p4("Person4", 14);
	Person p5("Person5", 15);
	Person p6("Person6", 16);
	Person p7("Person7", 17);
	Person p8("Person8", 18);
	Person p9("Person9", 19);

	shared_ptr<LinkedList<Person>> ll(new LinkedList<Person>());
	ll->AddElements(p1);
	ll->AddElements(p2);
	ll->AddElements(p3);
	ll->AddElements(p4);
	ll->AddElements(p5);
	ll->AddElements(p6);
	ll->AddElements(p7);
	ll->AddElements(p8);
	ll->AddElements(p9);

	

	for (int i = 0; i < ll->Size();i++)
	{
		Person p = ll->GetElementAt(i);
		p.PrintDetails();
	}

	cout << "\n Index of Person 3 is:  " << ll->IndexOf(p3) << endl;

	cout << "\n Remove Person3 at 3 from list \n" << endl;

	ll->RemoveAt(3);

	for (int i = 0; i < ll->Size();i++)
	{
		Person p = ll->GetElementAt(i);
		p.PrintDetails();
	}

	cout << "\nRemove person 4 \n" << endl;

	ll->RemoveElement(p4);

	for (int i = 0; i < ll->Size();i++)
	{
		Person p = ll->GetElementAt(i);
		p.PrintDetails();
	}


	cout << "\n Remove Last \n" << endl;

	ll->RemoveAt(ll->Size() - 1);

	for (int i = 0; i < ll->Size();i++)
	{
		Person p = ll->GetElementAt(i);
		p.PrintDetails();
	}

	cout << "\n The index of Person 5 is : " << ll->IndexOf(p5) << endl;

	cout << "\n Size of List at End " << ll->Size() << endl;

	cout << "\n Add More elements \n" << endl;

	Person p10("Person10", 20);

	ll->AddElementAt(p10, 0);

	for (int i = 0; i < ll->Size();i++)
	{
		Person p = ll->GetElementAt(i);
		p.PrintDetails();
	}

	cout << "\nPrint in Reverse \n" << endl;

	for (int i = ll->Size() - 1; i >= 0;i--)
	{
		Person p = ll->GetElementAt(i);
		p.PrintDetails();
	}

	cout << "\n Remove First \n" << endl;

	ll->RemoveAt(4);

	for (int i = 0; i < ll->Size();i++)
	{
		Person p = ll->GetElementAt(i);
		p.PrintDetails();
	}
	
}

