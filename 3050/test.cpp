template<class _Ty,
	class _Elem = char,
	class _Traits = char_traits<_Elem> >
	class ostream_iterator
{	// wrap _Ty inserts to output stream as output iterator
public:
	using iterator_category = output_iterator_tag;
	using value_type = void;
	using difference_type = void;
	using pointer = void;
	using reference = void;

	using char_type = _Elem;
	using traits_type = _Traits;
	using ostream_type = basic_ostream<_Elem, _Traits>;

	ostream_iterator(ostream_type& _Ostr, const _Elem * const _Delim = 0)
		: _Mydelim(_Delim), _Myostr(_STD addressof(_Ostr))
	{	// construct from output stream and delimiter
	}

	ostream_iterator& operator=(const _Ty& _Val)
	{	// insert value into output stream, followed by delimiter
		*_Myostr << _Val;
		if (_Mydelim != 0)
		{
			*_Myostr << _Mydelim;
		}

		return (*this);
	}

	ostream_iterator& operator*()
	{	// pretend to return designated value
		return (*this);
	}

	ostream_iterator& operator++()
	{	// pretend to preincrement
		return (*this);
	}

	ostream_iterator& operator++(int)
	{	// pretend to postincrement
		return (*this);
	}

protected:
	const _Elem * _Mydelim;	// pointer to delimiter string (NB: not freed)
	ostream_type * _Myostr;	// pointer to output stream
};