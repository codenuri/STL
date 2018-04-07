#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	//vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
	list<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	auto p = find( begin(v), end(v), 3);

	return 0;
}



















//
