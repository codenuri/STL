#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    modulus<int> m; // % 연산을 수행하는 함수 객체

    int n = m(10, 3); // 10 % 3 = 1


    int x[5] = { 9, 9,2,4,3};

    // 3의 배수가 아닌 것을 찾고 싶다.!

    find_if ( x, x+5, m ); //

}

















//












//
