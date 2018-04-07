#include <iostream>
#include <memory>
#include "car.h"
using namespace std;

int main()
{
    weak_ptr<Car> wp;

    {
        shared_ptr<Car> sp( new Car );

        wp = sp;
    }// 대상 객체 파괴.

    if ( wp.expired() ) {}
}












//
