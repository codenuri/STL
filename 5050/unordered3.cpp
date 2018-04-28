#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

struct Point
{
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
};

// Point 의 해쉬 함수 객체
struct PointHash
{
    size_t operator()(const Point& p) const
    {
        hash<int> hi;
        return hi(p.x) + hi(p.y);
    }
};

struct PointEqual
{
    bool operator()(const Point& p1, const Point& p2) const
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
};


int main()
{
    //set<Point> s;  // < 필요, ==필요 없다.

    unordered_set<Point, PointHash, PointEqual> s;  // hash<int>, hash<Point>

    s.insert( Point(1,1)); // hash 함수에 전달
    s.insert( Point(2,2)); // == 도 필요하다.
    s.insert( Point(3,4));

    s.find(Point(1,1));
}


















//
