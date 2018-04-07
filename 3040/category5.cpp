#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 1, 2 ������ �ּ� �䱸 ����? - �Է¹ݺ���
	auto p = find(begin(v), end(v), 5);

	reverse(begin(v), end(v));// �����.

	sort(begin(v), end(v)); // quick sort
							// ���� ���� �ݺ���.

	forward_list<int> s = { 1,2,3 };
	reverse(begin(s), end(s)); // error


	list<int> s2 = { 1,2,3 };
	sort(begin(s2), end(s2)); // error

	s2.sort(); // ok.

	vector<int> v = { 1,2,3 };

	v.sort();  // ��� �Լ� sort()�� ������ ?
				// ����.  �Ϲ� �Լ�(�˰���) 
				// sort()�� ����ϸ� �ȴ�.

	for (auto& n : v)
		cout << n << ", ";
}