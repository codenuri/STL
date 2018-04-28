#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
    thread::id id = this_thread::get_id();

    cout << id << endl;
    
    this_thread::sleep_for( 3s );
    this_thread::sleep_until( chrono::system_clock::now() + 3s);
    this_thread::yield();

}
