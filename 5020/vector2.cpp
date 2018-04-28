#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10,0);

    v.resize(7);    // ?

    cout << v.size()     << endl; // 7
    cout << v.capacity() << endl; // 10

    v.push_back(0);
    cout << v.size()     << endl; // 8
    cout << v.capacity() << endl; // 10

    v.pop_back();
    cout << v.size()     << endl; // 7
    cout << v.capacity() << endl; // 10

    v.shrink_to_fit();
    cout << v.size()     << endl; // 7
    cout << v.capacity() << endl; // 7


    v.push_back(0);

    cout << v.size()     << endl; // 7
    cout << v.capacity() << endl; // 7

    








}
