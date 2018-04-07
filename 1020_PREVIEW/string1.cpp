#include <iostream>
#include <string.h> // CÇì´õ
#include <string>   // STL string
using namespace std;

int main()
{
//	char s1[10] = "hello";
//	char s2[10];

	string s1 = "hello";
	string s2;

	s2 = s1;		// strcpy(s2, s1) 

	if (s1 == s2)	// strcmp(s1, s2)
	{
	}
	string s3 = s1 + s2;

	cout << s3 << endl;
}