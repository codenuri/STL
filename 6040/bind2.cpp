#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

class Test
{
public:
    int data = 0;

    void f(int a, int b) // void f( Test* this, int a, int b)
    {
        data = a;
        printf("f : %d, %d\n", a, b);
    }
};

int main()
{
    Test t;

    // 객체를 고정하는 경우
//    bind(&Test::f, &t, 1, 2)(); // t.f(1,2)
//    bind(&Test::f, t, 1, 2)(); // t.f(1,2)
//    bind(&Test::f, ref(t), 1, 2)(); // t.f(1,2)

    // 객체를 인자로 전달하는 경우.
//    bind(&Test::f, _1, 1, 2)(&t); // t.f(1,2)
//    bind(&Test::f, _1, 1, 2)(t); // t.f(1,2)


    bind(&Test::data, &t)() = 10; // t.data = 10

    cout << t.data << endl; // 1
}





















//
