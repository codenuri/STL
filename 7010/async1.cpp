#include <iostream>
#include <thread>
#include <future>
using namespace std;

int f1()
{
    this_thread::sleep_for(3s);
    return 10;
}

int main()
{
//    thread t(&f1);
//    t.join();

    future<int> ft = async( launch::async, &f1);

    cout << "main routine" << endl;

    //cout << ft.get() << endl; // 스레드 종료를 대기.
}
