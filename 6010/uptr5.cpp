#include <iostream>
#include <memory>
using namespace std;


int main()
{
    shared_ptr<int> sp(new int);
    unique_ptr<int> up(new int);

    shared_ptr<int> sp1 = up;       // error
    shared_ptr<int> sp2 = move(up); // ok

    unique_ptr<int> up1 = sp;       // error.
    unique_ptr<int> up2 = move(sp); // error.
}
















//
