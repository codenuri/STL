#include <iostream>
using namespace std;


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};


template<typename T> class slist_iterator
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

	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head);
	}
	slist_iterator<T> end()
	{
		return slist_iterator<T>(0);
	}
};

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	slist_iterator<int> p = s.begin();

	cout << *p << endl; // 50
	++p;
	cout << *p << endl; // 40

	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}