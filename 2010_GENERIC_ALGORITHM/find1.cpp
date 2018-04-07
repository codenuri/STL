#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[] = "abcdefg";

	char* p = strchr(s, 'c');

	if (p == 0)
		cout << "fail" << endl;
	else
		cout << "success : " << *p << endl;
}
