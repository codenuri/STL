#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//list<int> s = { 1,2,3,4,5 };

	vector<int> s = { 1,2,3,4,5 };

	reverse(s.begin(), s.end());

	// 
//	for (int i = 0; i < s.size(); i++)
//		cout << s[i] << endl;
	/*
	vector<int>::iterator p = s.begin();

	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
	*/

	for (auto& n : s)
		cout << n << endl;
}
