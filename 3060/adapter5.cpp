#include <iostream>
#include <iterator>
#include <vector>
#include "People.h"
using namespace std;

int main()
{
    vector<People> v;
    v.push_back(People("A"));
    v.push_back(People("B"));
    v.push_back(People("C"));
    v.push_back(People("D"));

    cout << "------------------------" << endl;

    //vector<People> v2(begin(v), end(v));
    vector<People> v2(make_move_iterator(begin(v)),
                      make_move_iterator(end(v)));


/*
    auto p1 = begin(v);

    People peo1 = *p1; // 복사 생성자..

    // 방법 1.
    move_iterator< vector<People>::iterator > p2(p1);

    People peo2 = *p2; // move 생성자..
    //People peo3 = move(*p1); // move 생성자..

    // 방법 2.
    auto p3 = make_move_iterator(begin(v));
*/
}















//
