#include <iostream>
#include <memory>

struct shared_ptr_control_base
{
    virtual ~shared_ptr_control_base() { }

    void decrement_count_shared() noexcept { m_shared--; }
    void increment_count_shared() noexcept { m_shared++; }
    void decrement_count_weak() noexcept { m_weak--; }
    void increment_count_weak() noexcept { m_weak++; }
    virtual void destroy_shared(void*) noexcept = 0;
    virtual void destruct()            noexcept = 0;

    uint32_t m_shared = 1;
    uint32_t m_weak   = 0;
};

template <typename AllocatorTypeControl, typename AllocatorTypeShared, typename SharedType>
struct shared_ptr_control_derived : shared_ptr_control_base
{
    shared_ptr_control_derived() = delete;
    shared_ptr_control_derived(const shared_ptr_control_derived<AllocatorTypeControl, AllocatorTypeShared, SharedType>&) = delete;

    shared_ptr_control_derived(shared_ptr_control_derived<AllocatorTypeControl, AllocatorTypeShared, SharedType>&& a_that) :
        m_allocatorControl(std::move(a_that.m_allocatorControl)),
        m_allocatorShared(std::move(a_that.m_allocatorShared))
    {

    }

    shared_ptr_control_derived<AllocatorTypeControl, AllocatorTypeShared, SharedType>&
        operator = (const shared_ptr_control_derived<AllocatorTypeControl, AllocatorTypeShared, SharedType>&) = delete;
    shared_ptr_control_derived<AllocatorTypeControl, AllocatorTypeShared, SharedType>&
        operator = (shared_ptr_control_derived<AllocatorTypeControl, AllocatorTypeShared, SharedType>&&) = delete;

    shared_ptr_control_derived(AllocatorTypeControl&& a_allocatorC,
                               AllocatorTypeShared&& a_allocatorS) :
        m_allocatorControl(a_allocatorC),
        m_allocatorShared(a_allocatorS)
    {

    }

    void destroy_shared(void* a_pointer) noexcept
    {
        m_allocatorShared.destroy(static_cast<SharedType*>(a_pointer));
        m_allocatorShared.deallocate(static_cast<SharedType*>(a_pointer), 1);
    }

    void destruct() noexcept
    {
        decltype(m_allocatorControl) l_temp = std::move(m_allocatorControl);
        l_temp.m_allocator.destroy(this);
        l_temp.m_allocator.deallocate(this, 1);
    }

    mutable AllocatorTypeControl m_allocatorControl;
    mutable AllocatorTypeShared  m_allocatorShared;
};

template <template <typename t> class T, typename AllocatorTypeShared, typename SharedType>
struct Wrangler
{
    T<shared_ptr_control_derived<Wrangler, AllocatorTypeShared, SharedType>> m_allocator;
};

template <typename SharedType> struct shared_ptr;

template <typename SharedType> struct weak_ptr
{
    friend struct shared_ptr<SharedType>;

    weak_ptr() : m_pointer(nullptr), m_control(nullptr) { }

    weak_ptr(const weak_ptr<SharedType>& a_that) :
        m_pointer(a_that.m_pointer),
        m_control(a_that.m_control)
    {
        std::cout << "weak_ptr<T>::weak_ptr(const weak_ptr<T>&)" << std::endl;

        if (m_control != nullptr)
        {
            m_control->increment_count_weak();
        }
    }

    weak_ptr(weak_ptr<SharedType>&& a_that) :
        m_pointer(a_that.m_pointer),
        m_control(a_that.m_control)
    {
        std::cout << "weak_ptr<T>::weak_ptr(shared_ptr<T>&&)" << std::endl;

        a_that.m_pointer = nullptr;
        a_that.m_control = nullptr;
    }

    weak_ptr(const shared_ptr<SharedType>& a_that) :
        m_pointer(a_that.m_pointer),
        m_control(a_that.m_control)
    {
        std::cout << "weak_ptr<T>::weak_ptr(const shared_ptr<T>&)" << std::endl;

        if (m_control != nullptr)
        {
            m_control->increment_count_weak();
        }
    }

    weak_ptr<SharedType>& operator=(const weak_ptr<SharedType>& a_rhs)
    {
        std::cout << "weak_ptr<T>& weak_ptr<T>::operator = (const weak_ptr<T>&)" << std::endl;

        if (a_rhs.m_control != m_control)
        {
            if (m_control != nullptr) { decrement_destruct(); }

            m_pointer = a_rhs.m_pointer;
            m_control = a_rhs.m_control;

            if (m_control != nullptr) { m_control->increment_count_weak(); }
        }

        return *this;
    }

    weak_ptr<SharedType>& operator=(weak_ptr<SharedType>&& a_rhs)
    {
        std::cout << "weak_ptr<T>& weak_ptr<T>::operator = (weak_ptr<T>&&)" << std::endl;

        if (a_rhs.m_control != m_control)
        {
            if (m_control != nullptr) { decrement_destruct(); }
        }

        m_pointer = a_rhs.m_pointer;
        m_control = a_rhs.m_control;
        a_rhs.m_pointer = nullptr;
        a_rhs.m_control = nullptr;

        return *this;
    }

    weak_ptr<SharedType>& operator=(const shared_ptr<SharedType>& a_rhs)
    {
        std::cout << "weak_ptr<T>& weak_ptr<T>::operator = (const shared_ptr<T>&)" << std::endl;

        if (a_rhs.m_control != m_control)
        {
            if (m_control != nullptr) { decrement_destruct(); }

            m_pointer = a_rhs.m_pointer;
            m_control = a_rhs.m_control;

            if (m_control != nullptr) { m_control->increment_count_weak(); }
        }

        return *this;
    }

    ~weak_ptr()
    {
        if (m_control) { decrement_destruct(); }
    }

    void decrement_destruct()
    {
        m_control->decrement_count_weak();

        if (m_control->m_weak == 0)
        {
            if (m_control->m_shared == 0)
            {
                std::cout << "weak_ptr -> destructing control block" << std::endl;

                m_control->destruct();
            }
        }
    }

    SharedType* operator->() const noexcept { return m_pointer; }

    SharedType& operator*() const noexcept { return *m_pointer; }

    explicit operator bool() const noexcept { return m_control ? m_control->m_shared : false; }

    uint32_t use_count() const noexcept { return m_control ? m_control->m_shared : 0; }

    SharedType* get() const noexcept { return m_pointer; };

private:
    SharedType* m_pointer;
    shared_ptr_control_base* m_control;
};

template <typename SharedType> struct friend_struct;

template <typename SharedType> struct shared_ptr
{
    friend friend_struct<SharedType>;
    friend struct weak_ptr<SharedType>;

    shared_ptr() : m_pointer(nullptr), m_control(nullptr) { }

    shared_ptr(const shared_ptr<SharedType>& a_that) :
        m_pointer(a_that.m_pointer),
        m_control(a_that.m_control)
    {
        std::cout << "shared_ptr<T>::shared_ptr(const shared_ptr<T>&)" << std::endl;

        if (m_control != nullptr)
        {
            m_control->increment_count_shared();
        }
    }

    shared_ptr<SharedType>& operator=(const shared_ptr<SharedType>& a_rhs)
    {
        std::cout << "shared_ptr<T>& shared_ptr<T>::operator = (const shared_ptr<T>&)" << std::endl;

        if (a_rhs.m_control != m_control)
        {
            if (m_control != nullptr) { decrement_destruct(); }

            m_pointer = a_rhs.m_pointer;
            m_control = a_rhs.m_control;

            if (m_control != nullptr) { m_control->increment_count_shared(); }
        }

        return *this;
    }

    ~shared_ptr()
    {
        if (m_control) { decrement_destruct(); }
    }

    SharedType* operator->() const noexcept { return m_pointer; }

    SharedType& operator*() const noexcept { return *m_pointer; }

    explicit operator bool() const noexcept { return m_pointer != nullptr; }

    uint32_t use_count() const noexcept { return m_control ? m_control->m_shared : 0; }

    void decrement_destruct()
    {
        m_control->decrement_count_shared();

        if (m_control->m_shared == 0)
        {
            std::cout << "shared_ptr -> destructing shared object" << std::endl;

            m_control->destroy_shared(m_pointer);

            if (m_control->m_weak == 0) { std::cout << "shared_ptr -> destructing control block" << std::endl; m_control->destruct(); }
        }
    }

    void reset() noexcept { shared_ptr<SharedType>().swap(*this); }

    void reset(SharedType* const a_pointer) noexcept { shared_ptr<SharedType>(a_pointer).swap(*this); }

    void swap(shared_ptr<SharedType>& a_that) noexcept { std::swap(m_pointer, a_that.m_pointer); std::swap(m_control, a_that.m_control); }

    SharedType* get() const noexcept { return m_pointer; };

private:
    SharedType* m_pointer;
    shared_ptr_control_base* m_control;
};

template <typename SharedType>
struct friend_struct
{
    template <typename T>
    shared_ptr_control_base*& get_ref_pointer_control(T& a_r_shared_ptr) { return a_r_shared_ptr.m_control; }

    template <typename T>
    SharedType*& get_ref_pointer_shared(T& a_r_shared_ptr) { return a_r_shared_ptr.m_pointer; }
};

template <typename SharedType,
          template <typename t> class AllocatorControl = std::allocator,
          template <typename t> class AllocatorShared = std::allocator,
          typename... Args>

shared_ptr<SharedType> make_shared(Args&&... args)
{
    using AllocatorControlCreate = Wrangler<AllocatorControl, AllocatorShared<SharedType>, SharedType>;

    shared_ptr_control_derived<AllocatorControlCreate, AllocatorShared<SharedType>, SharedType>
        l_d(std::move(AllocatorControlCreate()),
            std::move(AllocatorShared<SharedType>()));

    auto* l_pC = l_d.m_allocatorControl.m_allocator.allocate(1);
    SharedType* l_pS = nullptr;

    try
    {
        l_pS = l_d.m_allocatorShared.allocate(1);
    }
    catch (...)
    {
        l_d.m_allocatorControl.m_allocator.deallocate(l_pC, 1); throw;
    }

    try
    {
        l_d.m_allocatorControl.m_allocator.construct(l_pC, std::move(l_d));
    }
    catch (...)
    {
        l_d.m_allocatorControl.m_allocator.deallocate(l_pC, 1); l_d.m_allocatorShared.deallocate(l_pS, 1); throw;
    }

    try
    {
        l_pC->m_allocatorShared.construct(l_pS, SharedType(std::forward<Args>(args)...));
    }
    catch (...)
    {
        l_pC->m_allocatorControl.m_allocator.destroy(l_pC);
        l_pC->m_allocatorControl.m_allocator.deallocate(l_pC, 1); l_pC->m_allocatorShared.deallocate(l_pS, 1); throw;
    }

    shared_ptr<SharedType> l_s;
    friend_struct<SharedType>().get_ref_pointer_control(l_s) = l_pC;
    friend_struct<SharedType>().get_ref_pointer_shared(l_s) = l_pS;
    return l_s;
}

int main()
{
    auto shared_1 = make_shared<int>(47);
    auto shared_2 = shared_1;

    {
        auto shared_3 = shared_1;

        std::cout << shared_1.use_count() << std::endl;
    }

    shared_2.reset();

    weak_ptr<int> weak_1(shared_1);

    std::cout << weak_1.use_count() << std::endl;

    shared_1.reset();

    std::cout << weak_1.use_count() << std::endl;

    if (!weak_1)
    {
        std::cout << "weak_1 is no longer safe to use" << std::endl;
    }
}
