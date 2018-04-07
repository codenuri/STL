#include <iostream>
using namespace std;

int main()
{
	const char* s1 = "C:\\AA\\BB\\CC\\a.txt";

	//const char* s2 = R"(C:\AA\BB\CC\a.txt)";

	//const char* s2 = R"(C:\AA\BB\"""CC\a.txt)";

	const char* s2 = R"**(C:\AA\BB\)"CC\a.txt)**";

	cout << s2 << endl;
}

