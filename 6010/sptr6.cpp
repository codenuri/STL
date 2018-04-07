#include <iostream>
#include <memory>
#include "Car.h"
using namespace std;

void* operator new( size_t sz)
{
    cout << "new sz : " << sz << endl;
    return malloc(sz);
}

int main()
{
    //shared_ptr<Car> p1( new Car ;

//    shared_ptr<Car> p1 = make_shared<Car>();
//    shared_ptr<Car> p1 (make_shared<Car>());

    //f( shared_ptr<Car>(new Car), foo() );

    f( make_shared<Car>(), foo() );

    //

    shared_ptr<Car> p1 = allocate_shared<Car>(MyAlloc<Car>() );
}


















//
