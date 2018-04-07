#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> up1(new int);
    //unique_ptr<int> up2 = up1; // error.

    unique_ptr<int> up2 = move(up1); // ok. 


}
















//
