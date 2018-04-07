#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main()
{
	int n = 10;

	cout << n << endl;

	ostream_iterator<int> p(cout, ", ");

	*p = 20; // cout << 20 << ", "
	*p = 30; // cout << 30 << ", "

	list<int> s = { 1,2,3 };

	copy(begin(s), end(s), p);

	//fill_n(begin(s), 3, 0);

	fill_n( p , 3, 0); // 0, 0, 0,
}