
template<class _Container> class back_insert_iterator
{
public:
	using iterator_category = output_iterator_tag;
	using value_type = void;
	using difference_type = void;
	using pointer = void;
	using reference = void;

	using container_type = _Container;

	explicit back_insert_iterator(_Container& _Cont)
		: container(_STD addressof(_Cont))
	{	// construct with container
	}

	back_insert_iterator& operator=(const typename _Container::value_type& _Val)
	{	// push value into container
		container->push_back(_Val);
		return (*this);
	}

	back_insert_iterator& operator=(typename _Container::value_type&& _Val)
	{	// push value into container
		container->push_back(_STD move(_Val));
		return (*this);
	}

	back_insert_iterator& operator*()
	{	// pretend to return designated value
		return (*this);
	}

	back_insert_iterator& operator++()
	{	// pretend to preincrement
		return (*this);
	}

	back_insert_iterator operator++(int)
	{	// pretend to postincrement
		return (*this);
	}

protected:
	_Container * container;	// pointer to container
};