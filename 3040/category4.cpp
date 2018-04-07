#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> s1 = { 1,2,3 };

	auto i1 = begin(s1);
	auto i2 = i1;

	if (i1 == i2)
	{
		cout << (*i1 == *i2) << endl;
		cout << (++i1 == ++i2) << endl;
	}
}