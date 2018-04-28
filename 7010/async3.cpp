#include <iostream>
#include <thread>
#include <future>
using namespace std;

int f1()
{
    this_thread::sleep_for(3s);
    cout << "f1 end" << endl;
    return 10;
}

int main()
{
    //async( launch::async, &f1); // 리턴값으로 future<int> 객체
                                // 리턴용 임시객체

    future<int> ft = async( launch::async, &f1);

    cout << "main routine" << endl;

    //ft.get(); // 스레드 종료를 대기.
}
