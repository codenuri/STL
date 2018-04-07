#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

struct abs_greater
{
    bool operator()(int a, int b) const
    {
        return abs(a) > abs(b);
    }
};

int main()
{
    priority_queue<int, vector<int>, abs_greater > pq;

    pq.push(10);      // <      >
    pq.push(20);
    pq.push(-15);
    pq.push(12);

    cout << pq.top() << endl; // 20    10
    pq.pop();
    cout << pq.top() << endl; // 15    12
}
