#include <iostream>
using namespace std;

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

// member_type2.cpp
#include <iterator>
/*
template<typename Category,
		 typename T,
	     typename Distance = std::ptrdiff_t,
	     typename Pointer = T*,
	     typename Reference = T&>
struct iterator
{
	using iterator_category = Category;
	using value_type = T;
	using pointer = Pointer;
	using reference = Reference;
	using difference_type = Distance;
};
*/

template<typename T> 
class slist_iterator :
	public iterator< forward_iterator_tag, T >
{
	Node<T>* current = 0;
public:

	
	slist_iterator(Node<T>* p = 0) : current(p) {}

	slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	T& operator*() { return current->data; }

	bool operator ==(const slist_iterator& it)
	{
		return current == it.current;
	}
	bool operator !=(const slist_iterator& it)
	{
		return current != it.current;
	}
};


template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}
	using iterator = slist_iterator<T>;

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0); }
};


int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	slist<int>::iterator p = s.begin();

}