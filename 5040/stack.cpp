#include <iostream>
using namespace std;

// list 가 제공된다.
#include <list>
/*
// 그런데 stack 이 필요하다.
template<typename T, typename C = deque<T> > class stack
{
    C st;
public:
    inline void push(const T& a) { st.push_back(a);}
    inline void pop()            { st.pop_back();}
    inline T&   top()            { return st.back();}

    inline bool empty()          { return st.empty();}
};
*/
#include <vector>
#include <deque>
#include <stack>

int main()
{
//    stack<int, list<int, MyAlloc<int>> > s3;

    stack<int> s2;
    stack<int, vector<int>> s1;
    stack<int, list<int>> s;

    s.push(10);
    s.push(20);

    cout << s.top() << endl; // 20
    s.pop();

    cout << s.top() << endl; // 10
}












//
