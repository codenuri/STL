#include <iostream>
#include <algorithm>
using namespace std;

template<typename T, int N> struct Array
{
    T buf[N];

    typedef T* iterator;

    iterator begin() { return buf ;}
    iterator end()   { return buf + N;}

    int size() const { return N;}
    T& operator[](int n) { return buf[n];}
};

int main()
{
    Array<int, 5> ar = {1,2,3,4,5};

    //auto p = find( ++ar.begin(), ar.end(), 3);

    auto p = find( next(ar.begin()), ar.end(), 3);

    cout << *p << endl;
}




















//
