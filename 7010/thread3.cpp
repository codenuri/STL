#include <iostream>
#include <thread>
using namespace std;

void f1()      {}
void f2(int a) {}

struct Worker
{
    void Main() {}
};

struct Functor
{
    void operator()() {}
};

int main()
{
    thread t1(&f1);
    thread t2(&f2, 5);

    Worker w;
    thread t3(&Worker::Main, &w);

    Functor f; f();
    thread t4(f);

    thread t5( []() {cout << "thread t5" << endl;});


    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}
