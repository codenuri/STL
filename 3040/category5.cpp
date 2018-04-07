#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 1, 2 인자의 최소 요구 조건? - 입력반복자
	auto p = find(begin(v), end(v), 5);

	reverse(begin(v), end(v));// 양방향.

	sort(begin(v), end(v)); // quick sort
							// 임의 접근 반복자.

	forward_list<int> s = { 1,2,3 };
	reverse(begin(s), end(s)); // error


	list<int> s2 = { 1,2,3 };
	sort(begin(s2), end(s2)); // error

	s2.sort(); // ok.

	vector<int> v = { 1,2,3 };

	v.sort();  // 멤버 함수 sort()가 있을까 ?
				// 없다.  일반 함수(알고리즘) 
				// sort()를 사용하면 된다.

	for (auto& n : v)
		cout << n << ", ";
}