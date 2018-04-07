#include <iostream>
#include <memory>
using namespace std;

class Car
{
    int color;
public:
    ~Car() { cout << "~Car()" << endl;}

    void Go() { cout << "Car go" << endl;}
};

int main()
{
    //Car* p = new Car;
    shared_ptr<Car> p( new Car );

    //if ( 실패 ) return ;
    p->Go(); // p.operator->()
    (*p).Go(); // p.operator*()

    //delete p;
}
