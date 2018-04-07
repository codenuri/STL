#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	char a = 0, b = 0, c = 0;

	// x \t y \t z
	//cin >> a;	//	x
	//cin >> b;	//	y
	//cin >> c;	//	z

	a = cin.rdbuf()->sgetc();	// x
	b = cin.rdbuf()->snextc();	// \t
	c = cin.rdbuf()->snextc();	// y

	cout << a << "," << b << "," << c << endl;
}
