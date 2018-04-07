
#include <iostream>
#include <iterator>
using namespace std;

int* foo()
{
    static int x[10] = {1,2,3,4,5,6,7,8,9,10};
    return x;
}

int main()
{
    //++foo();
    auto p2 = next(foo());

    cout << *p2 << endl;
}
