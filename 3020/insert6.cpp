#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template<typename C> class eback_insert_iterator
{
	C* container;
public:
	using iterator_category = output_iterator_tag;

	using value_type = void;
	using pointer = void;
	using reference = void;
	using difference_type = void;

	using container_type = C;


	explicit eback_insert_iterator(C& c) : container( std::addressof(c) ) {}   // c.operator&()

	eback_insert_iterator& operator*()     { return *this; }
	eback_insert_iterator& operator++()    { return *this; }
	eback_insert_iterator& operator++(int) { return *this; }

	eback_insert_iterator& operator=(const typename C::value_type& a)
	{
		container->push_back(a);
		return *this;
	}
	eback_insert_iterator& operator=(const typename C::value_type&& a)
	{
		container->push_back(move(a));
		return *this;
	}
};

int main()
{
	list<int> s = { 1,2 };
	eback_insert_iterator<list<int>> p(s);

	*p = 30;

	int x[2] = { 1,2 };
	copy(x, x + 2, p); // ++p


	for (auto& n : s)
		cout << n << ", ";
}

