#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

class Test
{
public:
    int data = 10;
};

int main()
{
    Test t1, t2;

    // 1.
    function<int&()> f1;
    f1 = bind( &Test::data, &t1); // t1.data를 보관
    cout << f1() << endl; // t1.data . getter
    f1() = 20; // t1.data = 20
    cout << t1.data << endl; // 20

    // 2. 객체를 function 인자로 전달하는 방식

    function<int&(Test*)> f2;

    f2 = bind(&Test::data, _1);
    f2(&t1) = 20;
    f2(&t2) = 30;

    cout << t1.data << endl; // 20;
    cout << t2.data << endl; // 30;

}





















//
