// g++ iterator1.cpp -std=c++1z -lstdc++fs

#include <iostream>
#include <list>
#include <experimental/filesystem>
using namespace std;
using namespace std::experimental::filesystem;

int main()
{
	directory_iterator p("C:\\windows");

	cout << *p << endl;
	++p;
	cout << *p << endl;
}










