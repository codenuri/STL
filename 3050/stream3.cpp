#include <iostream>
#include <iterator>
using namespace std;

int main()
{
//	ostream_iterator<int> p(cout, ", ");

	ostreambuf_iterator<char> p(cout); // wchar_t
	
	*p = 65; // 'A'
}
