#include <iostream>
#include <vector>
using namespace std;

class Point
{
    int x, y;
public:
    Point(int a, int b) : x(a), y(b){ cout << "Point()" << endl; }

    ~Point() { cout << "~Point()" << endl;}

    Point(const Point& ) { cout << "Point(const Point&)" << endl;}
};

int main()
{
    vector<Point> v;

    // 1.
    //Point p1(10, 20);
    //v.push_back(p1 );

    // 2. 임시객체로 넣기
    //v.push_back( Point(10,20));

    // 3. 객체 자체를 vector가 만들게 한다.
    // 객체를 전달하지 말고, 생성자 인자를 전달한다.
    //v.emplace_back( 10, 20 ); // emplace_front()
                                // insert ==> emplace


    Point p1(10, 20); // 객체 생성
    // p1 사용...

    //v.push_back(p1 );
    v.push_back( move(p1) );

    // p1은 이제 필요 없다.

    cout << "-----------" << endl;
}




























//
