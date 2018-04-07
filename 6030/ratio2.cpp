#include <iostream>
#include <ratio>
using namespace std;

int main()
{
    ratio_add< ratio<1,4>, ratio<2,4> > r2; // 3/4

    cout << r2.num << endl; // 3
    cout << r2.den << endl; // 4


    ratio<1, 1000> r3; // milli
    ratio<1000, 1> r4; // kilo

    milli m;
    kilo  k;
    cout << k.num << endl; // 1000
    cout << k.den << endl; // 1


}
