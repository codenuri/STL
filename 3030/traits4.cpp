#include <iostream>
#include <list>
#include <iterator>
using namespace std;

template<typename T> void foo(T a)
{
	// T�� �ݺ��� �϶� �ݺ��ڰ� 
	// ����Ű�� Ÿ���� ����ϰ� �ʹ�.

	typename T::value_type n1;

	typename iterator_traits<T>::value_type n2;

}






