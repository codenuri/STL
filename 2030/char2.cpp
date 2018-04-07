#include <iostream>
#include <string>
using namespace std;

int main()
{
	const char    s1[] = "abcd";
	const wchar_t s2[] = L"abcd"; // wide character

	const char16_t s3[] = u"abcd"; // UTF-16
	const char32_t s4[] = U"abcd"; // UTF-32

	const char s5[] = u8"abcd"; // UTF-8

	const char32_t s6[] = UR"(abcd)"; // UTF-32

}
