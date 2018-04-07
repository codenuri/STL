#include <iostream>
#include <memory>
using namespace std;

void foo(int* p )
{
    cout << "foo" << endl;
    delete p;
}

struct Deleter
{
    void operator()(int* p ) const
    {
         delete p;
    }
};


int main()
{
    //shared_ptr<int> sp( new int, foo);

    // 1. 함수객체 사용
    // unique_ptr<int, Deleter> up( new int);

    // 2. 함수 포인터 사용
    // unique_ptr<int, void(*)(int*) > up( new int, foo);

    // 3. 람다 표현식 사용.
    auto f = [](int* p ) { delete p; cout << "lambda" << endl;};

    unique_ptr<int, decltype(f) > up( new int, f);

    unique_ptr<int[] > up( new int[10]);
}































//
