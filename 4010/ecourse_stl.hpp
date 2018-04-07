/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang@codenuri.co.kr
* COURSENAME : C++ STL Programming
* MODULE     : ecourse_stl.hpp

* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <iterator>
#include <algorithm>
using namespace std::literals;

class stop_watch
{
	std::string message;
	std::chrono::high_resolution_clock::time_point start;
public:
	inline stop_watch(std::string msg = "") : message(msg) { start = std::chrono::high_resolution_clock::now(); }

	inline ~stop_watch()
	{
		std::chrono::high_resolution_clock::time_point end =
					std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

		std::cout << message << " " << time_span.count()
				  << " seconds." << std::endl;;
	}
};

template<typename F, typename ... A>
decltype(auto) chronometry(F&& f, A&& ... args)
{
	stop_watch sw;
	return std::invoke(std::forward<F>(f),
					   std::forward<A>(args)...);
}

template<typename Container> void show(Container&& c)
{
	for (const auto& n : c)
		std::cout << n << ", ";
	std::cout << std::endl;
}

template<typename InputIter>
void show(InputIter first, InputIter last )
{
	std::copy(first, last,
		std::ostream_iterator<typename std::iterator_traits<InputIter>::value_type>(std::cout, ", "));
	std::cout << std::endl;
}
