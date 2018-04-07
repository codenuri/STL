#include <iostream>
#include <memory>
#include "Car.h"
using namespace std;

int main()
{
    Car* p = new Car;

    shared_ptr<Car> sp1(p);  // 제어 블럭 생성.
    shared_ptr<Car> sp2(p);  // 제어 블럭 생성.


    shared_ptr<Car> sp3( new Car);  // RAII

    shared_ptr<Car> sp3 = make_shared<Car>();
}
