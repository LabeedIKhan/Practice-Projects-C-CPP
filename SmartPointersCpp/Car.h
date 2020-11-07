#pragma once

#include <string>
#include <iostream>

using namespace std;

class Car
{
protected:
	int speed;
	string company;
	string type;
	bool isavailable;

public:

	Car(int speed, string company, string type, bool isavailable) : speed(speed), company(company), type(type), isavailable(isavailable) {}

	~Car() {}

	void SetSpeed(const int &speed);

	void SetCompany(const string &company);

	void SetType(const string& type);

	void SetAvailabilityconst(const bool& isavailable);

	int& GetSpeed();

	string& GetCompany();

	string& GetType();

	bool& GetAvailability();

	virtual void PrintDescription();
};


class Train : public Car {

private:
	int length;

public:

	Train(int speed, string company, string type, bool isavailable, int length);

	~Train();

	void SetLength(const int& length);

	int& GetLength();

	void PrintDescription() override;
};

