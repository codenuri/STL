#include <iostream>
#include <memory>
using namespace std;

struct Deleter
{
//    int a;
//    int b;

    void operator()(int* p ) const
    {
         delete p;
    }
};

int main()
{
    unique_ptr<int, Deleter> up(new int);
    unique_ptr<int, Deleter2> up2(new int);

    cout << sizeof(up) << endl;

    shared_ptr<int> sp1( new int, foo);
    shared_ptr<int> sp2( new int, goo);


    unique_ptr<int> up3 = make_unique<int>();
}































//
