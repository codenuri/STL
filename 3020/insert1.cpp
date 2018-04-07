// insert1.cpp
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(int argc, char** argv)
{
	list<int> s = { 1, 2, 3, 4, 5};

	//s.push_back(10);


	back_insert_iterator< list<int> > p( s );

	//*p = 20; // s.push_back(20);



	int x[5] = { 10,20,30,40,50 };

//	for (int i = 0; i < 5; i++)
//		s.push_back(x[i]);

	copy(x, x + 5, p);



	for ( auto& n : s )
		cout << n << endl; 
}
