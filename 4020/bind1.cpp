#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 인자를 4개 전달.

    //bind(&foo, 4개의 인자  );

    // 4항 -> 0항으로
    bind(&foo, 1,2,3,4)(); // 인자가 없는 함수.
    bind(&foo, 10,_1,20,_2)(3, 5); // 10, 3, 20, 5

    // 4항을 -> 3항으로
    bind(&foo,5, _3, _1, _2)( 10, 20, 30); // 5, 30, 10, 20

    // 4항 => 2항..
    bind(&foo, _2, 4, 2, _1)(7, 9); // 9, 4, 2, 7
}













//
