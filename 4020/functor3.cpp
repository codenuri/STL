#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include "ecourse_stl.hpp"
using namespace std;

int foo( int a, int b) { return a + b;}

int main()
{
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2,3,4,5};
    vector<int> v3 = {0,0,0,0,0};

    //transform(begin(v1),end(v1),begin(v2),begin(v3), foo);

    //plus<int> p;
    //transform(begin(v1),end(v1),begin(v2),begin(v3), p);

    //transform(begin(v1),end(v1),begin(v2),begin(v3), plus<int>());

    // C++11 람다 표현식
    transform(begin(v1),end(v1),begin(v2),begin(v3),
                    [](int a, int b) { return a + b;});

    show(v3);
	return 0;
}



















//
