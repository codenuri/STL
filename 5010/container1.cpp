#include <iostream>
#include <list>
#include <stack>
#include <set>
using namespace std;

struct Point
{
     int x;
     int y;
 };

int main()
{
    /*
    list<Point> s;
    Point pt;
    s.push_back(pt);

    list<Point>::value_type n; // Point
    list<Point>::iterator  p; // 반복자 타입

    //auto p = s.begin();
    auto p1 = begin(s);

*/
    list<int> s;

    s.push_back(10);
    s.push_back(20);
    s.push_back(30);

//    cout << s.pop_back() << endl; // error
    cout << s.back() << endl; // 30
    s.pop_back();
    cout << s.back() << endl; // 30

}














//
