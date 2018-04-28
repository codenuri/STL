#include <iostream>
#include <thread>
#include <future>
using namespace std;

void f1( promise<int>& p )
{
    this_thread::sleep_for(3s);
    p.set_value(10);
}

int main()
{
    promise<int> p;
    future<int> ft = p.get_future();

    thread t(&f1, ref(p));
    cout << "wait value " << endl;
    cout << "value : " << ft.get() << endl; // 대기

    t.join();
}
