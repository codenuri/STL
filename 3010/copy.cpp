#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	int x[5] = { 1, 2, 3, 4, 5 };
	int y[5] = { 0, 0, 0, 0, 0 };
	
	list<int> s2 = { 0,0,0,0,0 };

//	for (int i = 0; i < 5; i++)
//		y[i] = x[i];

	copy(x, x + 5, begin(s2));

	for (auto& n : s2)
		cout << n << ", ";
	
	



}