#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
//    double distance = 3; // 3m, 3km, 3cm

    duration<double, ratio<1,1>> d1(3); // 3m
//    duration<double, ratio<1,1000>> d2(d1); // milli 3000
//    duration<double, ratio<1000,1>> d3(d1); // km


    duration<double, milli> d2(d1); // milli 3000
    duration<double, kilo> d3(d1); // km
    cout << d2.count() << endl; // 3000
    cout << d3.count() << endl; // 0.003

    using MilliMeter = duration<double, milli>;
    using KiloMeter = duration<double, kilo>;
    using Meter = duration<double, ratio<1,1>>;


    Meter m(3);
    KiloMeter km(m);

    cout << km.count() << endl; // 0.003


}





//
