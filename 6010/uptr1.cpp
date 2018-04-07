#include <iostream>
#include <memory>
#include "Car.h"
using namespace std;

int main()
{
    shared_ptr<Car> sp1(new Car);
    shared_ptr<Car> sp2 = sp1;  // ok. 참조 계수 2.

    auto f = [](Car* p) { delete p;}
    unique_ptr<Car, decltype(f)> up1(new Car, f); // 자원 독점

    unique_ptr<Car, void(*)(Car*)> up1(new Car, foo); // 자원 독점

    //unique_ptr<Car> up2 = up1; // error.

    cout << sizeof(sp1) << endl;
    cout << sizeof(up1) << endl;
}
