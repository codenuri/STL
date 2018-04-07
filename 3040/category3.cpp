#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> s1 = { 1,2,3 };

	auto i = begin(s1);

	int n = *i; // 입력
	*i = 20; // 출력

	++i; // ok

	i = i + 2; // ++i 를 2번했을때와 동일하다.

}