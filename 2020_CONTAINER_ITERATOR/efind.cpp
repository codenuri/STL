
// efind.cpp

template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;

	return first;
}
