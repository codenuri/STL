#include <iostream>
#include <set>
using namespace std;

struct Point
{
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}

    bool operator<(const Point& p) const {  return x < p.x;    }
};

/*
struct PointLess
{
    bool operator()(const Point& p1, const Point& p2) const
    {
        return p1.x < p2.x;
    }
};
*/
int main()
{
    set<Point> s;

    s.insert( Point(1,1));
    s.insert( Point(2,2));  // <
    s.insert( Point(3,3));

    s.insert( Point(2,2)); // ==
                            // if ( newelem < oldelem ) left
                            // else if ( oldelm < newelem ) right
                            // else  같다고 생성

    s.find( Point(3,3)); // ==

    s.emplace( 1, 3); // Point(1,3)


}


















//
