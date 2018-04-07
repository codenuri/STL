#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>  // plus<>
#include "ecourse_stl.hpp"
using namespace std;

int foo( int a, int b) { return a + b;}

int main()
{
    list<int> s1 = {1,2,3,4,5};
    list<int> s2 = {1,2,3,4,5};
    list<int> s3 = {0,0,0,0,0};

    //transform( begin(s1), end(s1), begin(s2) , foo);

    //transform( begin(s1), end(s1), begin(s2), begin(s3), foo);

    //transform( begin(s1), end(s1), begin(s2), begin(s3),
    //                        multiplies<int>());

    transform( begin(s1), end(s1), begin(s2), begin(s3),
                                [](int a,int b) { return a +b;});


    show(s3); // 2, 4, 6, 8, 10
	return 0;
}



















//
