#include <iostream>
#include <iterator>
using namespace std;


template<typename T, typename CharT = char, typename Traits = char_traits<CharT> > class eostream_iterator
{
	//	ostream*    stream;
	basic_ostream<CharT, Traits>* stream;

	const CharT* delimiter;
public:

	using iterator_category = output_iterator_tag;
	using value_type = void;
	using pointer = void;
	using reference = void;
	using difference_type = void;

	using char_type = CharT;
	using traits_type = Traits;
	using ostream_type = basic_ostream<CharT, Traits>;



	eostream_iterator(ostream& os, const CharT* const deli = 0) : stream(&os), delimiter(deli) {}

	eostream_iterator& operator*() { return *this; }
	eostream_iterator& operator++() { return *this; }
	eostream_iterator& operator++(int) { return *this; }

	eostream_iterator& operator=(const T& v)
	{
		*stream << v;
		if (delimiter != 0)
			*stream << delimiter;

		return *this;
	}
};

int main()
{
	eostream_iterator<int> p(cout, ", ");

	*p = 10; // ( p.operator*() ).operator=(10)
}



