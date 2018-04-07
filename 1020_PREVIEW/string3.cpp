#include <iostream>
#include <string>
#include <complex>
//using namespace std;
using std::cout;
using std::endl;
using std::string;

//using namespace std::string_literals;
//using namespace std::literals;

void foo(string s)      { cout << "string" << endl;}
void foo(const char* s) { cout << "char*" << endl; }

int main()
{
//	using namespace std::literals;

	foo("hello"); // char*
	foo("hello"s); // string

	std::complex<double> c = 3i;
}