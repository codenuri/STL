#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	//ostream_iterator<int> p1(cout);

	istream_iterator<int> p1(cin);

	int n = *p1;

	cout << n << endl;
	
}
