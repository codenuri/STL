#include <iostream>
#include <list>
#include <algorithm>
#include "ecourse_stl.hpp"
using namespace std;

int foo(int a) { return a + 10;}

int main()
{
    list<int> s1 = { 1,2,3,4,5};
    list<int> s2;// = { 0,0,0,0,0};


    //transform( begin(s1), end(s1), begin(s2), foo );

    transform( begin(s1), end(s1), back_inserter(s2), foo );


    show(s2);

	return 0;
}



















//
