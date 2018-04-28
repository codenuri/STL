#include <iostream>
#include <string>
#include <functional>
using namespace std;

int main()
{
    hash<int> hi;
    hash<double> hd;
    hash<string> hs;

    cout << hi(50) << endl;
    cout << hd(3.4) << endl;
    cout << hs("hello") << endl;

}
