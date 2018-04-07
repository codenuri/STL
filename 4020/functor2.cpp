#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/*
struct Plus
{
    int operator()(int a, int b) const
    {
        return a + b;
    }
};
*/

int main()
{
    plus<int> p;

    cout << p(1,2) << endl; // 3

    multiplies<int> m;
    cout << m(3,4) << endl; // 12

	return 0;
}





















//
