#include <iostream>
#include <cstring>
using namespace std;

char* estrchr(char* first, char* last, char value)
{
	while (first != last && *first != value)
		++first;

	return first == last ? 0 : first;
}

int main()
{
	char s[] = "abcdefg";

	char* p = estrchr(s, s + 4,  'e');

	if (p == 0)
		cout << "fail" << endl;
	else
		cout << "success : " << *p << endl;
}
