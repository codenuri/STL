#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include "ecourse_stl.hpp"
using namespace std;

int main()
{
    list<int> s;
    //deque<int> s;
    //vector<int> s;

    s.push_front(10);
    s.push_back(20);

    cout << s[0] << endl;

    show(s);
}
