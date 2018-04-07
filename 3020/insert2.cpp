// insert2.cpp
#include <iostream>
#include <list>
using namespace std;

/*
template<typename T> 
back_insert_iterator<T>  // 리턴 타입
back_inserter(T& c)
{
	return back_insert_iterator<T>(c);
}
*/

int main(int argc, char** argv)
{
	int x[5] = { 10,20,30,40,50 };
	list<int> s = { 1, 2, 3, 4, 5 };
	
	//copy(x, x + 5, s.begin()); // 덮어쓴다.

	// back_insert_iterator< list<int>> p(s);
	// copy(x, x + 5, p);

	copy(x, x + 5, back_inserter( s) );


	for (auto& n : s)
		cout << n << endl; 
}
