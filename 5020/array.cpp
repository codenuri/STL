#include <iostream>
#include <vector>
using namespace std;

/*
template<typename T, int N> struct array
{
    T buf[N];

    typedef T* iterator;

    iterator begin() { return buf ;}
    iterator end()   { return buf + N;}

    int size() const { return N;}

    T& operator[](int n) { return buf[n];}
};
*/
#include <array>

int main()
{
//    int x[5];
//    vector<int> v(5);

    array<int, 5> arr = {1,2,3,4,5};

    //arr.push_back(10);

    cout << arr.size() << endl;
}









//
