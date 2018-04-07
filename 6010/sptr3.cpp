#include <iostream>
#include <memory>
#include "car.h"
#include "MyAlloc2.h"
using namespace std;

void foo( Car* p )
{
    cout << "Delete Car" << endl;
    delete p;
}
int main()
{
    //shared_ptr<Car> p( new Car ); // delete

    //shared_ptr<Car> p( new Car, foo );
    //shared_ptr<Car> p( new Car, [](Car* p) { delete p; } );

    shared_ptr<Car> p( new Car,
                      [](Car* p) { delete p; },
                     MyAlloc<Car>() );



}

























//
