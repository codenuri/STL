#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template<typename T>
void eadvance_imp(T& p, int n,
	              random_access_iterator_tag)
{
	p = p + n;
}

template<typename T>
void eadvance_imp(T& p, int n,input_iterator_tag)
{
	while (n--)	++p;
}

template<typename T>
void eadvance(T& p, int n)
{
	// int*
	eadvance_imp(p, n,
	typename iterator_traits<T>::iterator_category());
}


int main()
{
//	vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	int s[10] = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = begin(s);

	eadvance(p, 5);

	cout << *p << endl;
}



