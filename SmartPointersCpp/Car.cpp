#include "Car.h"

void Car::SetSpeed(const int& speed)
{
    this->speed = speed;
}

void Car::SetCompany(const string& company)
{
    this->company = company;
}

void Car::SetType(const string& type)
{
    this->type = type;
}

void Car::SetAvailabilityconst(const bool& isavailable)
{
    this->isavailable = isavailable;
}

int& Car::GetSpeed()
{
    return this->speed;
}

string& Car::GetCompany()
{
    return this->company;
}

string& Car::GetType()
{
    return this->type;
}

bool& Car::GetAvailability()
{
    return this->isavailable;
}

void Car::PrintDescription()
{
    cout << "This car Speed is " << this->speed << " The car Company is " << 
        this->company << " Car type is " << this->type << " car status is " 
        << boolalpha << this->isavailable << endl;
}

Train::Train(int speed, string company, string type, bool isavailable, int length) : Car(speed, company, type, isavailable)
{
    this->length = length;
}

Train::~Train()
{
}

void Train::SetLength(const int& length)
{
    this->length = length;
}

int& Train::GetLength()
{
    return this->length;
}

void Train::PrintDescription()
{
    cout << "This Train Speed is " << this->speed << " The Train Company is " << this->company 
        << " Train type is " << this->type << " train status is " << this->isavailable 
        << " Train Length is " << this->length << endl;
}
