#include <iostream>
#include <algorithm>
using namespace std;

template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;

	return first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 10, 5);

	if (p == x + 10)
		cout << "fail" << endl;
	else
		cout << "success : " << *p << endl;
}
