#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main()
{
    modulus<int> m; // % 연산을 수행하는 함수 객체

    int n = m(10, 3); // 10 % 3  => 1    이항 함수 객체..

    //------------------------------------

    int x[5] = { 3,6, 9, 2, 5};

    // 3의 배수가 아닌 것을 찾고 싶다.  => % 연산
    //auto p = find(x, x+5, 3); // ?

    //auto p = find_if( x, x+5, m); // error. 단항을 요구하는데..
                                    // m은 이항이다..

    // 2항을 단항으로 변경
    //auto p = find_if( x, x+5, bind(m,_1, 3)  );

    auto p = find_if( x, x+5, [](int a) { return a % 3 != 0;});
}












//












//
