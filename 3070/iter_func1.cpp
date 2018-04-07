#include <iostream>
#include <iterator>
#include <forward_list>
using namespace std;

int main()
{
    int x[10] = { 1,2,3,4,5,6,7,8,9,10};

    forward_list<int> s = { 1,2,3,4,5,6,7,8,9,10};

    auto p1 = next(begin(s));

    advance(p1, 3); // p1 + 3;

    cout << *p1 << endl; // 5

    cout << distance( begin(s), p1) << endl; // p1 - begin(s)

    iter_swap(p1, begin(s));

    cout << *p1 << endl; // 1
}
