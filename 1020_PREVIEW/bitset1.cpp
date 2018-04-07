#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main()
{
	//bitset<8> b1; // 0
	//bitset<8> b1 = 0xf0; // 11110000
	bitset<8> b1 = 0b11110000;

	b1.set(); // 모두 1로
	b1.reset(); // 모두 0으로

	b1.set(1); // 0000 0010
	b1[2] = 1; // 0000 0110
	b1[0].flip(); // 0000 0111


	if (b1.test(1) == true) {}
	if (b1[1] == true) {}

	if (b1.none() == true) {}

	int n2 = b1.count(); 
	cout << n2 << endl; // 3


	bitset<8> b2 = 0b00001111;
	bitset<8> b3 = 0b11110000;
	bitset<8> b4 = b2 | b3;

	cout << b4 << endl;




	cout << b1 << endl;

	string s		= b1.to_string();
	unsigned long n = b1.to_ulong();

	cout << s << endl;
	cout << n << endl;
	
}
