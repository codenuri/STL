#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
T* efind(T* first, T* last, T value)
{
	while (first != last && *first != value)
		++first;

	return first == last ? 0 : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = efind(x, x + 10, 5);

	if (p == 0)
		cout << "fail" << endl;
	else
		cout << "success : " << *p << endl;
}
