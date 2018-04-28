#include <iostream>
#include <memory>
#include <vector>
#include "Point.h"
using namespace std;

int main()
{
    //Point* p = new Point[2];

    allocator<Point> a;

    Point* p = a.allocate(2); //  operator new()

    a.construct( p ); //
    a.construct( p+1, 1, 2); //


    a.destroy(p);   // 소멸자 호출.
    a.destroy(p+1);

    a.deallocate(p, 2);

    //---------------
    vector<Point> v; // vector<Point, allocator<Point>>

    if ( v.get_allocator() == a )
        cout << "same" << endl;

}







//
