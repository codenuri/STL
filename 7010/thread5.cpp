#include <iostream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

int global = 0;
mutex m;

void f1()
{
    lock_guard<mutex> lg(m); // 생성자에서 m.lock

    //m.lock();
    global = 100;
    global = global + 1;
    //m.unlock();
}

int main()
{
    thread t1(&f1);
    thread t2(&f1);

    t1.join();
    t2.join();
}






//
