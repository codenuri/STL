#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "ecourse_stl.hpp"
using namespace std;

int main()
{
	vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	auto p = remove(begin(v), end(v), 3);

	show(v);  // 1,2,1,2,1,2,1, 2,3,1

	v.erase(p, end(v));

	show(v);  // 1,2,1,2,1,2,1

	return 0;
}



















//
