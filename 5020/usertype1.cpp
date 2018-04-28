#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point
{
public:
    int x, y;
public:
    // 디폴트 생성자가 없다.
    Point(int a, int b) : x(a), y(b) {}

    // < 와 == 를 제공한다.
    bool operator<(const Point& p) const
    {
        return x < p.x;
    }
    bool operator==(const Point& p) const
    {
        return x == p.x;
    }

};

int main()
{
    vector<Point> v1;
    vector<Point> v2(10, Point(0,0));
    v2.resize(20, Point(0,0));

    sort(begin(v2), end(v2)); // 크기 비교 ?


    //sort(begin(v2), end(v2),
    //    [](const Point& p1, const Point& p2) { return p1.x > p2.y;});
}


























//
