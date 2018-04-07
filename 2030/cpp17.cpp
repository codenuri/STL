#include <iostream>
#include <list>
using namespace std;

template<typename T> class List
{
public:
	List(int sz, T initValue) {}
};

int main()
{
	List<int> s1(10, 0);
	List      s2(10, 0); // C++17 บฮลอ ok.

	list<int> s3 = { 1,2,3 };
	list      s4 = { 1,2,3 }; // C++17 style
}