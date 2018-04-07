#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

int main()
{

    system_clock::time_point tp = system_clock::now();

    // 1970년 1월 1일 0시 기준.
    nanoseconds ns = tp.time_since_epoch();

    cout << ns.count() << endl;

    hours h = duration_cast<hours>(ns);
    cout << h.count() << endl;

    // time_point => string
    time_t t = system_clock::to_time_t(tp);
    string s = ctime(&t);
    cout << s << endl;

}
















//
