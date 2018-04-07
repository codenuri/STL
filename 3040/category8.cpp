#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;




// tag dispatching ��� ���� - "C++ Template Programming ����" ����.
// 1. �Լ� ���ڸ� ����� �����ε�.
/*
template<typename T> void eadvance_imp(T& p, int n, random_access_iterator_tag)
{
	p = p + n;
}

template<typename T> void eadvance_imp(T& p, int n, input_iterator_tag)
{
	while (n--)	++p;
}

template<typename T> void eadvance(T& p, int n)
{
	eadvance_imp(p, n, typename T::iterator_category());
}
*/

// 2. C++17 if constexpr ���.
#include <type_traits>

/*
template<typename T> void eadvance(T& p, int n)
{
	if constexpr (is_same< typename T::iterator_category, random_access_iterator_tag>::value)
	{
		p = p + n;
	}
	else
		while (n--) ++p;
}
*/
// 3. enable_if �� ���..   SFINAE ���� ���.

template<typename T> 
typename enable_if<is_same<typename T::iterator_category,random_access_iterator_tag>::value>::type
eadvance(T& p, int n)
{
	p = p + n;
}

template<typename T> 
typename enable_if<! is_same<typename T::iterator_category, random_access_iterator_tag>::value>::type
eadvance(T& p, int n)
{
	while (n--) ++p;
}



int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = begin(s);

	eadvance(p, 5);

	cout << *p << endl;
}


