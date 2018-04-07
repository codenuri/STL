#include <iostream>
#include <string>
using namespace std;

template<typename CharT,
		 typename Traits = char_traits<CharT>, 
		 typename Allocator = allocator<CharT> >
class basic_string 
{
};
using string    = basic_string<char>;
using u16string = basic_string<char16_t>;


template<typename CharT, 
		 typename Traits = char_traits<CharT>>
class basic_ostream 
{
};
using ostream = basic_ostream<char>;
using wostream = basic_ostream<wchar_t>;


int main()
{
	string s1 = "hello";
	u16string s2 = u"hello";

	cout << "a"; // ostream
	wcout << L"AA"; // wostream
}

