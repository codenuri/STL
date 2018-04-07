#include <iostream>
using namespace std;

void func1(int a, int b, int c, int d)
{
    printf("func : %d, %d, %d, %d\n", a,b, c,d );
}

void func2(int& a)
{
    a = 20;
}

class Test
{
public:
    int data;

    void mfunc(int a, int b, int c, int d)
    {
        data = a;
        printf("mfunc : %d, %d, %d, %d\n", a, b, c,d );
    }
};
