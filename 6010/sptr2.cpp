#include <iostream>
#include <memory>
#include "car.h"
using namespace std;

int main()
{
//    int a = 0; // copy initialization/
//    int a(0);  // direct initialization

    //shared_ptr<Car> p = new Car; // error
    shared_ptr<Car> p(new Car);  // ok
    shared_ptr<Car> p1(new Car);
    cout << sizeof(p1) << endl;

//    shared_ptr<Car> p2 = p1;

}

























//
