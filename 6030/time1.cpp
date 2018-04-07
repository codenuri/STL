#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    /*
    using seconds      = duration<int>; // duration<int, ratio<1,1>>
    using minutes      = duration<int, ratio<60,1>>;
    using hours        = duration<int, ratio<3600>>; // ratio<3600,1>
    using milliseconds = duration<int, milli>;
    */
    hours h(1);
    minutes m(h); // 60
    seconds s(h); // 3600

    cout << m.count() << endl;
    cout << s.count() << endl;

    //hours h2( s); // 1 error
    hours h2 = duration_cast<hours>(s);

    cout << h2.count() << endl;

    using days = duration<int, ratio<3600 * 24, 1>>;

    days d(1);

    minutes m2(d);

    cout << m2.count() << endl;  // 60 * 24

}













//
