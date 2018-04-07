#include <iostream>
#include <string>
#include <memory>
using namespace std;


struct People
{
    People(string s) : name(s) {}
    ~People() { cout << "~People : " << name << endl;}

    string name;
    weak_ptr<People> bf;
};

int main()
{
    shared_ptr<People> p1( new People("KIM"));
//    {
        shared_ptr<People> p2( new People("LEE"));

        p1->bf = p2;
        p2->bf = p1;

//    } // p2 자원 파괴...

    // if ( p1->bf.expired() ) {}

    shared_ptr<People> sp2 = p1->bf.lock();

    if ( sp2 )
        cout << sp2->name << endl;
    else
        cout << "destroy bf" << endl;



}








//
