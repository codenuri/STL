#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

class Test
{
public:
    int data = 0;

    void f(int a, int b)
    {
        data = a;
        printf("f : %d, %d\n", a, b);
    }
};

int main()
{
    Test t;

    // 1. 일반 함수 모양의 function
    function<void(int)> f1;

    f1 = bind(&Test::f, &t, _1, 20);

    f1(10); // t.f(10, 20)


    // 2. 객체를 function 의 인자로 받는 방법
    function<void(Test*, int)> f2;
    f2 = bind(&Test::f, _1, _2, 20);
    f2(&t, 100); // t.f(100, 20)


    function<void(Test, int)> f3;

    f3 = bind(&Test::f, _1, _2, 20);

    f3(t, 200); // t.f(200, 20)



    function<void(Test&, int)> f4;

    f4 = bind(&Test::f, _1, _2, 20);

    f4(t, 300); // t.f(300, 20)

    cout << t.data << endl; // 300
}





















//
