#include <cstddef>

template<typename T>
class MyAlloc
{
public:
    using value_type = T;

    MyAlloc() noexcept {}

    template<typename U>
    MyAlloc(const MyAlloc<U>&) noexcept {}

    T* allocate(std::size_t num)
    {
        return static_cast<T*>(::operator new(sizeof(T) * num));
    }
    void deallocate(T* p, std::size_t num)
    {
        ::operator delete(p);
    }
};
template <class T1, class T2>
bool operator== (const MyAlloc<T1>&, const MyAlloc<T2>&) noexcept
{
	return true;
}
template <class T1, class T2>
bool operator!= (const MyAlloc<T1>&, const MyAlloc<T2>&) noexcept
{
	return false;
}
