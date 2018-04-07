#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool foo( int a) { return a % 3 == 0;}
int main()
{
    vector<int> v = { 6, 9, 3, 1, 2};

    // find 는 정말 generic 한가 ?

    // 주어진 구간에서 첫번째 나오는 3의 배수를 찾고 싶다.

    //auto p = find( begin(v), end(v), 3);

    //auto p = find_if( begin(v), end(v), foo);

    auto p = find_if( begin(v), end(v),
                    [](int a) { return a % 3 == 0;});

    cout << *p << endl;
}
























//
