#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

void f1(int a, int b, int c) { printf("f1 : %d, %d, %d\n", a,b,c);}
void f2(int& a)              { a = 20;}

int main()
{
//    bind(&f1, 1,2,3)( ); // f1(1,2,3)
//    bind(&f1, 1,2,_1)(10); // f1(1,2,10)
//    bind(&f1, 1,_2,_1)(10, 20); // f1(1,20,10)

    int n = 0;
    //bind(&f2, n)(); // f2(n)

//    reference_wrapper<int> r(n);
//    bind(&f2, r)();

    bind(&f2, ref(n))(); // cref : 

    cout << n << endl; // 20 ?  0
}
