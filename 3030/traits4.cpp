#include <iostream>
#include <list>
#include <iterator>
using namespace std;

template<typename T> void foo(T a)
{
	// T가 반복자 일때 반복자가 
	// 가리키는 타입을 사용하고 싶다.

	typename T::value_type n1;

	typename iterator_traits<T>::value_type n2;

}






