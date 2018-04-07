#include <iostream>
#include <memory>
#include "car.h"
using namespace std;

int main()
{
//    shared_ptr<Car> p1( new Car[10], [](Car* p) { delete[] p;} );

//    p1[0].Go(); // error


    //shared_ptr<Car> p1( new Car[10]); // bug - delete[], [] 연산없음
    shared_ptr<Car[]> p1( new Car[10]); //  delete[],   []연산있음

    p1[0].Go();
}

























//
