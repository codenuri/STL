#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> s1 = { 1,2,3 };

	auto i = begin(s1);

	int n = *i; // �Է�
	*i = 20; // ���

	++i; // ok

	i = i + 2; // ++i �� 2���������� �����ϴ�.

}