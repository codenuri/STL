#include <iostream>
#include <memory>
#include <thread>
#include "Car.h"
using namespace std;

class Worker : public enable_shared_from_this<Worker> // CRTP
{
    Car c;
    shared_ptr<Worker> holdMe;
public:
    void Run()
    {
        //holdMe = this;
        //holdMe = p

        holdMe = shared_from_this();

        thread t(&Worker::Main, this);
        t.detach();
    }
    void Main()
    {
        c.Go();     // 멤버 data(Car) 사용
        cout << "finish thread" << endl;

        holdMe.reset();
    }
};

int main()
{
    {
        shared_ptr<Worker> sp = make_shared<Worker>();
        sp->Run();
    }
    getchar();
}








//
