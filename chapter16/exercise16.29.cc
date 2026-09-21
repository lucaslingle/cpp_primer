/*
Revise your `Blob` class to use your version of `shared_ptr`
rather than the library version.
*/

#include <iostream>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>
#include <list>
#include <functional>

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

template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename Iter> Blob(Iter b, Iter e);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    T& operator[](size_type i);
private:
    MySharedPtr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob(): data(MySharedPtr<std::vector<T>>(new std::vector<T>())) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
    data(MySharedPtr<std::vector<T>>(new std::vector<T>(il))) { }

template <typename T>
template <typename Iter> 
Blob<T>::Blob(Iter b, Iter e):
    data(MySharedPtr<std::vector<T>>(new std::vector<T>(b, e))) { }

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}
