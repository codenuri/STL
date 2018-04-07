#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct People
{
    People(string s) : name(s) {}
    ~People() { cout << "~People : " << name << endl;}

    string name;
//    shared_ptr<People> bf; // best friend

    People* bf;  // Raw Pointer : 참조계수가 증가하지 않는다.
                 // 단점 : 대상 객체가 파괴었는지 알수 없다.
                 // weak_ptr
};

int main()
{
    shared_ptr<People> p1( new People("KIM"));
    {
        shared_ptr<People> p2( new People("LEE"));

    //    p1->bf = p2;
    //    p2->bf = p1;

        p1->bf = p2.get();
        p2->bf = p1.get();
    } // p2 자원 파괴...

    if ( p1->bf != 0 )
        cout << p1->bf->name << endl; //

}








//
