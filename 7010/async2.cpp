#include <iostream>
#include <thread>
#include <future>
using namespace std;

int f1()
{
    cout << "f1 : " << this_thread::get_id() << endl;
    this_thread::sleep_for(3s);
    return 10;
}

int main()
{
    cout << "main : " << this_thread::get_id() << endl;

    //future<int> ft = async( launch::async, &f1);

    // f1을 지연된 실행(get을 호출할때).
    //future<int> ft = async( launch::deferred, &f1);

    future<int> ft = async( launch::deferred | launch::async, &f1);

    this_thread::sleep_for(1s);

    cout << "main routine" << endl;

    cout << ft.get() << endl;
}









//
