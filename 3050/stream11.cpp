#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	ifstream f("stream11.cpp");

	//istream_iterator<char> p1(f), p2;

	istreambuf_iterator<char> p1(f), p2;
	ostream_iterator<char> p3(cout);

	//*p3 = *p1;

	copy(p1, p2, p3);
}