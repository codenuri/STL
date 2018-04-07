#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	string s1 = "hello";
	char s2[10];

	//strcpy(s2, s1); // string => const char* º¯È¯

	strcpy(s2, s1.c_str()); // s1.data()

	string s3 = "3.4";

	double d = stod(s3);

	cout << d << endl; // 3.4

	string s4 = to_string(5.4);
	cout << s4 << endl;


}