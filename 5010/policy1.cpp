#include <iostream>
using namespace std;

template<typename T,
         typename Allocator = allocator<T> > class vector
{
    //....
    Allocator ax;
public:
    void push_back(const T& a)
    {
        // 메모리 할당이 필요하다.
        // new, malloc, 공유 메모리, pool,
        T* p = ax.allocate(1);

        ax.deallocate(p, 1);

    }
};

int main()
{
    vector<int, MyAlloc> v;

    v.push_back(10);
}









//
