#include <iostream>
#include <memory>
#include "car.h"
#include "ecourse_alloc.hpp"
#include "MyAlloc2.h"
using namespace std;

void foo( Car* p)
{
    cout << "Car delete" << endl;
    delete p;
}

int main()
{
    //shared_ptr<Car> p( new Car); // delete

    //shared_ptr<Car> p( new Car, foo );

    shared_ptr<Car> p( new Car,
            [](Car* p) { cout << "Car Delete" << endl; delete p;},
            MyAlloc<int>() );



}

























//
