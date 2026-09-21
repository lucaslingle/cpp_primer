/*
Write your own versions of `shared_ptr` and `unique_ptr`. 
*/

#include <iostream>
#include <cstddef>
#include <functional>
#include <memory>

template <typename T> class MySharedPtr {
private:
    T* p = nullptr;
    std::size_t* refcount = nullptr;
    std::function<void(T*)> d = [](T* ptr) { delete ptr; };
    void release() {
        if (refcount && --*refcount == 0) {
            d(p);
            delete refcount;
        }
    }
    void refcount_init() {
        try {
            refcount = new std::size_t(1);
        } catch (...) {
            d(p); 
            throw;
        }
    }
public:
    MySharedPtr() = default;
    explicit MySharedPtr(T* ptr): p(ptr) { refcount_init(); }
    MySharedPtr(T* ptr, std::function<void(T*)> del): p(ptr), d(del) { refcount_init(); }
    MySharedPtr(const MySharedPtr &rhs): p(rhs.p), refcount(rhs.refcount), d(rhs.d) {
        if (refcount)
            ++*refcount;
    }
    MySharedPtr(MySharedPtr &&rhs) noexcept : p(rhs.p), refcount(rhs.refcount), d(std::move(rhs.d)) {
        rhs.p = nullptr;
        rhs.refcount = nullptr;
    }
    MySharedPtr& operator=(const MySharedPtr &rhs) {
        if (this != &rhs) {
            release();
            p = rhs.p;
            refcount = rhs.refcount;
            d = rhs.d;
            if (refcount)
                ++*refcount;
        }
        return *this;
    }
    MySharedPtr& operator=(MySharedPtr &&rhs) noexcept {
        if (this != &rhs) {
            release();
            p = rhs.p;
            refcount = rhs.refcount;
            d = std::move(rhs.d);
            rhs.p = nullptr;
            rhs.refcount = nullptr;
        }
        return *this;
    }
    ~MySharedPtr() {
        release();
    }
    T& operator*() const { return *p; }
    T* operator->() const { return p; }
    T* get() const noexcept { return p; }
    std::size_t use_count() const noexcept { return refcount ? *refcount : 0; }
    explicit operator bool() const noexcept { return p != nullptr; }
};

template <typename T, typename D = std::default_delete<T>> class MyUniquePtr {
private:
    T* p = nullptr;
    D d; 
public:
    MyUniquePtr() = default;
    explicit MyUniquePtr(T* ptr): p(ptr) { }
    MyUniquePtr(T* ptr, D del): p(ptr), d(del) { }
    MyUniquePtr(const MyUniquePtr &rhs) = delete;
    MyUniquePtr(MyUniquePtr &&rhs) noexcept : p(rhs.p), d(std::move(rhs.d)) { 
        rhs.p = nullptr;
    }
    MyUniquePtr& operator=(const MyUniquePtr &rhs) = delete;
    MyUniquePtr& operator=(MyUniquePtr &&rhs) noexcept {
        if (this != &rhs) {
            d(p);
            p = rhs.p;
            d = std::move(rhs.d);
            rhs.p = nullptr;
        }
        return *this;
    }
    ~MyUniquePtr() {
        d(p);
    }
    T& operator*() const { return *p; }
    T* operator->() const { return p; }
    T* get() const noexcept { return p; }
    explicit operator bool() const noexcept { return p != nullptr; }
};
    