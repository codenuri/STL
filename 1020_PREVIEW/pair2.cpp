#include <iostream>
#include <utility>
using namespace std;


// pair �� ���ڷ� ���� �޴� �Լ�.
template<typename T> void foo(T p)
{
	cout << p.first << ", " << p.second << endl;
}
/*
// �Լ� ���ø�
template<typename T1, typename T2>
pair<T1, T2> make_pair(const T1& a, const T2& b)
{
	return pair<T1, T2>(a, b);
}
*/

int main()
{
	pair<int, double> p1(1, 3.4);
	foo(p1);
	foo(pair<int, int>(1, 1));

	foo(make_pair(1, 1));

	foo(pair(1, 1)); // C++17 ���� ok..

}