#include <iostream>
#include <memory>
using namespace std;

class Shape {};
class Rect   : public Shape {};
class Circle : public Shape {};


unique_ptr<Shape> CreateShape(int type)
{
    unique_ptr<Shape> p;

    switch( type )
    {
    case 1: p.reset(new Rect);   break;
    case 2: p.reset(new Circle); break;
    }
    return p;
}

int main()
{
    //unique_ptr<Shape> p = CreateShape(1);

    shared_ptr<Shape> p1 = CreateShape(1);
    unique_ptr<Shape> p2 = CreateShape(1);
}
















//
