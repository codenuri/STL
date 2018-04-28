#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::rel_ops;
/*
namespace std
{
    namespace rel_ops   // relation operators
    {
        template<typename T>
        bool operator != ( const T& lhs, const T& rhs)
        {
            return ! ( lhs == rhs);
        }
    }
}
*/
class Point
{
public:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}

    bool operator<(const Point& p) const { return x < p.x;  }
    bool operator==(const Point& p) const { return x == p.x; }
};

int main()
{
    Point p1(1,1);
    Point p2(2,2);

    p1 == p2;
    p1 < p2;

    p1 > p2;
    p1 != p2;

}


























//
