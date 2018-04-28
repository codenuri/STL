#include <iostream>
#include <vector>
#include "ecourse_stl.hpp"
using namespace std;

int main()
{
    // vector 생성
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 3);
    vector<int> v4(v3);

    vector<int> v5 = {1,2,3,4};
    vector<int> v6{1,2,3,4};

    vector<int> v7(10,0); // 10 개를 0으로 초기화
    vector<int> v8{10,0}; // 2개를 10, 0 으로 초기화

    //----------------------
    vector<int> v;
    //v.push_front(10); // error.
    v.push_back(10);
    v.push_back(20);
    //v.insert( 위치,  30);

    v.insert( begin(v)+1,  30); // 10 30 20

    // 요소 꺼내기
    int n = v.front();
    int n1 = v[0];

    int x[5] = { 1,2,3,4,5};

    v.assign( x, x+5);

    //sort( begin(v), end(v));


    v[100] = 10;   // 예외 없이 runtime error
    //v.at(100) = 10; // 예외 발생

    for ( int i = 0; i < v.size(); i++)
        v[i] = 10; // ok
        v.at(i) = 10; // !!

    show(v);

}

















//
