#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;


void foo( seconds s) {}  // seconds s = 3


int main()
{
    // seconds => duration<int, ratio<1,1>>

    seconds s1(3);  // ok
    //seconds s2 = 3; // error
    seconds s3 = 3s;// ok.   seconds operator""s(3)
    seconds s4 = 3min;

    cout << s4.count() << endl; // 180

    //foo( 3 ); // error.
    foo( 3s); // ok

    //this_thread::sleep_for( 3min )

    seconds s5 = 3min + 40s;

    cout << s5.count() << endl; // 220

}
















//
