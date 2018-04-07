#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,3,9,10};

    auto ret = find( rbegin(s), rend(s), 3);

    auto p1 = begin(s);
	auto p2 = end(s);

    reverse_iterator< list<int>::iterator > r1(p2);

    auto r2 = make_reverse_iterator(p2);

    // reverse_iterator< list<int>::iterator >
    auto r3 = s.rbegin();
    auto r4 = rbegin(s);

    cout << *r1 << endl;
    cout << *r2 << endl;
    cout << *r3 << endl;
    cout << *r4 << endl;




}














//
