#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<typename T>
void sum(T first, T last)
{
	typename T::value_type s = 0;

	//...
}

int main()
{
	list<int> s = { 1,2,3 };
	
	sum( s.begin(), s.end() );

	//unsigned int n = s.size();

	list<int>::size_type n = s.size();
}

