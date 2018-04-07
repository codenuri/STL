#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;


template<typename T>
typename iterator_traits<T>::value_type
sum(T first, T last)
{
	//typename iterator_traits<T>::value_type s = 0;

	//decltype(*first) s = 0; // decltype( *포인터타입)

	typename 
	remove_reference<decltype(*first)>::type s = 0;


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
