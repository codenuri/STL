#include <iostream>
#include <memory>
#include <vector>
#include "Point.h"
#include "MyAlloc2.h"
using namespace std;

/*
template<typename T>
class MyAlloc
{
public:

};
*/
int main()
{
    vector<Point, MyAlloc<Point> > v;

    v.emplace_back(0,0);


    //allocator<Point> a;
    MyAlloc<Point> a;

    Point* p = a.allocate(1);   // 메모리 할당
    //a.construct(p, 1, 2);       // 생성자 호출
    //a.destroy(p);               // 소멸자 호출

    allocator_traits<decltype(a)>::construct(a, p, 1, 2);
    allocator_traits<decltype(a)>::destroy(a, p );


    a.deallocate(p, 1);         // 메모리 해지
}







//
