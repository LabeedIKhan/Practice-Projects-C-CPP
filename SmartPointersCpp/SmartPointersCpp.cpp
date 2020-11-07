
#include <iostream>
#include <list>
#include <memory>
#include <memory.h>
#include <vector>
#include "Car.h"


using namespace std;


static int alloc = 0;
static size_t allocsize = 0;

void* operator new(size_t size)
{
    alloc++;
    allocsize += size;
    return malloc(size);
}

void operator delete(void* mem, size_t size)
{
    alloc--;
    allocsize -= size;
    free(mem);
}

void PrintAllocation()
{
    cout << "\n Alocations are " << alloc << " Alocation size is " << allocsize << "  bytes "<< endl;
}

void RunSharedPtr() {

    shared_ptr<Car> car1(new Car(200, "Honda", "SUV", true));
    shared_ptr<Car> car2(new Car(180, "Toyota", "SUV", false));
    shared_ptr<Car> car3(new Car(240, "BMW", "Sports", true));
    shared_ptr<Car> car4(new Car(220, "Honda", "Van", true));
    shared_ptr<Car> car5(new Car(160, "Honda", "Off Road", true));

    list<shared_ptr<Car>> carlist;

    carlist.push_back(car1);
    carlist.push_back(car2);
    carlist.push_back(car3);
    carlist.push_back(car4);
    carlist.push_back(car5);

    Car* car6 = new Car(170, "Mercedes", "Sedan", false);
    Car* car7 = new Car(180, "Mercedes", "Sedan", true);

    carlist.push_back(shared_ptr<Car>(car6));
    carlist.push_back(shared_ptr<Car>(car7));

    carlist.push_back(make_shared<Car>(220, "Jaguar", "SUV", true));
    carlist.push_back(make_shared<Car>(220, "Jaguar", "Sedan", true));

    list<shared_ptr<Car>>::iterator carit;

    car1->PrintDescription();
    car5->PrintDescription();
    car7->PrintDescription();

    //Car* car = new Car(0, "memeory leak", " mem", false);
    // delete car;

    cout << "\n Iterate over complete list " << endl;

    for (carit = carlist.begin(); carit != carlist.end(); carit++)
    {
        (*carit)->PrintDescription();
    }
    
    PrintAllocation();
}

void PassUniqueUniquePtr(unique_ptr<vector<unique_ptr<Train>>> ut)
{
    vector<unique_ptr<Train>>::iterator trit;

    cout << "\nAfter passing Unique Ptr to function " << endl;
   
    for (trit = (*ut).begin(); trit != (*ut).end(); trit++)
    {
        (*trit)->PrintDescription();
    }
}

void PassSharedSharedPtr(shared_ptr<vector<shared_ptr<Train>>> ut)
{
    vector<shared_ptr<Train>>::iterator trit;

    cout << "\nAfter passing Shared Ptr to function " << endl;

    for (trit = (*ut).begin(); trit != (*ut).end(); trit++)
    {
        (*trit)->PrintDescription();
    }
}

void VectorUniquePtr()
{
    vector<unique_ptr<Train>> vectrain;

    vectrain.push_back(make_unique<Train>(300, "Arriva", "passenger", true, 500));
    vectrain.push_back(make_unique<Train>(300, "Virgin", "passenger", true, 500));
    vectrain.push_back(make_unique<Train>(300, "Virgin", "passenger", false, 400));

    vector<unique_ptr<Train>>::iterator trit;

    for (trit = vectrain.begin(); trit != vectrain.end(); trit++)
    {
        (*trit)->PrintDescription();
    }

    unique_ptr<vector<unique_ptr<Train>>> ut = make_unique<vector<unique_ptr<Train>>>(move(vectrain));

    PassUniqueUniquePtr(move(ut));

    PrintAllocation();
}

void VectorSharedPtr()
{
    vector<shared_ptr<Train>> vectrain;

    vectrain.push_back(make_unique<Train>(300, "Arriva", "passenger", true, 500));
    vectrain.push_back(make_unique<Train>(300, "Virgin", "passenger", true, 500));
    vectrain.push_back(make_unique<Train>(300, "Virgin", "passenger", false, 400));

    vector<shared_ptr<Train>>::iterator trit;

    for (trit = vectrain.begin(); trit != vectrain.end(); trit++)
    {
        (*trit)->PrintDescription();
    }

    shared_ptr<vector<shared_ptr<Train>>> st = make_shared<vector<shared_ptr<Train>>>(vectrain);

    PassSharedSharedPtr(st);

    PrintAllocation();
}

unique_ptr<Train> FunctionUnique(unique_ptr<Train> utrain)
{
    utrain->SetCompany("Virgin");
    utrain->SetLength(300);
    utrain->SetSpeed(150);
    return move(utrain);
}


void PassUniquePtr()
{
    cout << "\nCreate Unique Ptr in Function" << endl;

    unique_ptr<Train> utrain = make_unique<Train>(350, "Arriva", "Passenger", false, 200);

    utrain->PrintDescription();

    unique_ptr<Train> utrain2 = FunctionUnique(move(utrain));

    cout << "\nAfter Changing Value in Antoehr Function" << endl;

    utrain2->PrintDescription();

    PrintAllocation();
}


int main()
{
    RunSharedPtr();
    VectorUniquePtr();
    VectorSharedPtr();
    PassUniquePtr();
    PrintAllocation();
}




