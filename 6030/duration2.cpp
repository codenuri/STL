#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    using MilliMeter = duration<int, milli>;
    using KiloMeter  = duration<int, kilo>;
    using Meter      = duration<int, ratio<1,1>>;

    Meter      m(400);  // 600m
    MilliMeter mm(m);   // 600000    ok.. data 손실없다.
    //KiloMeter  km(m);   // 0.6 => 0 또는 1 error.

//    KiloMeter  km = duration_cast<KiloMeter>(m); // 버림.
    KiloMeter  km = round<KiloMeter>(m); // 반올림.

    cout << mm.count() << endl; // 600000
    cout << km.count() << endl; //


}





//
