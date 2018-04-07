#include <iostream>
#include <list>
#include <vector>
using namespace std;

// 인자로 전달된 컨테이너의 1번째 요소를 출력하는 함수
/*
void print(vector<int>& c)
{
	int n = c.front();
	cout << n << endl;
}
*/
/*
template<typename T>
void print(vector<T>& c)
{
	T n = c.front();
	cout << n << endl;
}
*/

template<typename T>
void print(T& c)
{
	// T : list<double>
	// T::value_type => list<double>::value_type
	//					==> double
	// typename : value_type을 타입의 이름으로 해석.
	typename T::value_type n = c.front(); // double

	cout << n << endl;
}

int main()
{
	list<double> v = { 1,2,3 };
	print(v);
}


/*
//------------------------
template<typename T> class list
{
public:
	typedef T value_type; // 핵심..

	using value_type = T; // C++11
};

list<int> s = { 1,2,3 };
list<int>::value_type n = s.front(); // n은 int
*/