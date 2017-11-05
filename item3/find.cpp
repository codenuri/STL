#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* p = find(x, x + 10, 5); // x ~ x+10 사이에서 5을 검색합니다.

	cout << *p << endl;	// 5
}
