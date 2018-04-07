#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(int argc, char** argv)
{
	int x[5]    = { 1, 2, 3, 4, 5 };
	list<int> s = { 0, 0, 0, 0, 0 };

	// 5, 4, 3, 2, 1, 0, 0, 0, 0, 0
	// 0, 1, 2, 3, 4, 5, 0, 0, 0, 0

	//back_insert_iterator< list<int> > p(s);
	//front_insert_iterator< list<int> > p(s);
	//insert_iterator< list<int> > p(s, s.begin());

	//copy(x, x + 5, p);

	//copy(x, x + 5, back_inserter(s) );
	//copy(x, x + 5, front_inserter(s));
	copy(x, x + 5, inserter(s, ++s.begin()));




	for (auto& n : s)
		cout << n << ", ";
}
