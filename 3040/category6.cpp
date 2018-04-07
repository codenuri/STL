#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template<typename T> 
void eadvance(T& p, int n)
{
	//p = p + 5;

	while (n--)
		++p;
}

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = begin(s);
	
	// �ݺ��� p�� 5ĭ �����ϰ� �ʹ�.
	//p = p + 5;
	eadvance(p, 5);

	cout << *p << endl;
}




