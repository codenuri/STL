#include <cstdlib>
#include <new>
#include <iostream>

template <typename T>
struct eallocator
{
  typedef T value_type;

  eallocator() = default;

  template <class U>
  constexpr eallocator(const eallocator<U>&) noexcept {}

  [[nodiscard]] T* allocate(std::size_t n)
  {
    std::cout << typeid(T).name() << std::endl;
    std::cout << "ealloc : " << n << std::endl;
    if(n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
    if(auto p = static_cast<T*>(std::malloc(n*sizeof(T)))) return p;
    throw std::bad_alloc();
  }

  void deallocate(T* p, std::size_t) noexcept { std::free(p); }
};

template <class T, class U>
bool operator==(const eallocator<T>&, const eallocator<U>&)
{
    return true;
}

template <class T, class U>
bool operator!=(const eallocator<T>&, const eallocator<U>&)
{
     return false;
}
