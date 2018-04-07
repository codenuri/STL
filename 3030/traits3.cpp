#include <iostream>
#include <list>
#include <vector>
using namespace std;

#include <iterator>

/*
template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

// 핵심 : 포인터 버전을 부분 특수화
template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};
*/

template<typename T>
typename iterator_traits<T>::value_type
sum(T first, T last)
{
	// T : int*
	//typename T::value_type s = 0;
	
	typename iterator_traits<T>::value_type s = 0;


	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}




int main()
{
	//list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	int s[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sum(begin(s), end(s));

	cout << n << endl;
}
