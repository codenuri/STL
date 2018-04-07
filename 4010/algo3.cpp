#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "ecourse_stl.hpp"
using namespace std;

int main()
{
	//vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	list<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	v.remove(3); // 당기는 것이 아니라 메모리 제거

	show(v); // 1,2,1,2,1,2,1,      2,3,1
/*
	auto p = remove(begin(v), end(v), 3);

	show(v);  // 1,2,1,2,1,2,1, 2,3,1

	v.erase(p, end(v));

	show(v);  // 1,2,1,2,1,2,1
*/
	return 0;
}



















//
