#include <iostream>
#include <string>
using namespace std;

int main()
{
	const char     s1[] = "abcd";
	const wchar_t  s2[] = L"abcd";	// wide character
	const char16_t s3[] = u"abcd";	// UTF-16
	const char32_t s4[] = U"abcd";	// UTF-32
	const char     s5[] = u8"abcd"; // UTF-8

	//cout << strlen(s1) << endl;

	cout << char_traits<char>::length(s1) << endl;
	cout << char_traits<char16_t>::length(s3) << endl;
}
