#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    stack<int> s1; // deque
    stack<int, vector<int>> s2;
    stack<int, list<int>> s3;
    s1.push(10);
    s1.pop();
    s1.top();

    queue<int> q1;
    queue<int, vector<int>> q2; // error
    queue<int, list<int>> q3;

    q1.push(10);
    q2.push(10); // push는 push_back 호출.
    q1.pop();    // ok
    q2.pop();    // error
    q1.front();

    priority_queue<int> pq;
}
