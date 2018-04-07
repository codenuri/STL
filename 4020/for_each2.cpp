#include <iostream>
#include <vector>
#include <algorithm>
#include "ecourse_stl.hpp"
using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // 1. 일반 함수 전달.
    for_each(begin(v), end(v), foo );

    // 2. 함수 객체를 전달.
    Show s;
    for_each(begin(v), end(v), s );

    // 3. 람다표현식
    for_each(begin(v), end(v), [](int a){ cout << a << endl;} );



	return 0;
}



















//
