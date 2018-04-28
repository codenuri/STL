#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main()
{
    //set<int> s;

    set<int, greater<int> > s;

    //s.push_front(10); // error
    s.insert(30);
    s.insert(40);   // < 연산으로 비교, >
    s.insert(20);
    s.insert(10);
    s.insert(45);
    s.insert(25);

    // 선형 검색..
    //auto p2 = find( begin(s), end(s), 10);
    //cout << *p2 << endl;

    auto p2 = s.find(10); // 이진 검색.
    cout << *p2 << endl;

    auto p = begin(s);

    //*p = 10;
    while( p != end(s))
    {
        cout << *p << endl;
        ++p;
    }
}










//
