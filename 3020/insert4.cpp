#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template<typename C>
class eback_insert_iterator
{
	C* container;
public:
	eback_insert_iterator(C& c) : container(&c) {}

	eback_insert_iterator& operator*() { return *this ; }

	eback_insert_iterator&
	operator=(const typename C::value_type& a)
	{
		container->push_back(a);
		return *this;
	}
};

int main()
{
	list<int> s = { 1,2 };
	eback_insert_iterator<list<int>> p(s);

	p = 20;
	*p = 30; // ( p.operator*() ).operator=(30)

	for (auto& n : s)
		cout << n << ", ";
}
