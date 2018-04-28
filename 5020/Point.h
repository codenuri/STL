#include <iostream>

struct Point
{
    int x;
    int y;

    Point(int a = 0, int b = 0) : x(a), y(b)
    {
        std::cout << "Point() : " << x << ", " << y << std::endl;
    }

    ~Point() { std::cout << "~Point()" << std::endl;}
};
