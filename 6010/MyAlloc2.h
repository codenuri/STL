#include <cstddef>
#include <iostream>

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
        std::cout << typeid(T).name() << std::endl;
        std::cout << "size : " << num << std::endl;
        return static_cast<T*>(::operator new(sizeof(T) * num));
    }
    void deallocate(T* p, std::size_t num)
    {
        std::cout << "delete : " << num << std::endl;
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
