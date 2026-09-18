/*
Add a constructor that takes two iterators to your `Blob` template.
*/

#include <iostream>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <cstddef>
#include <list>

template <typename T> class BlobPtr;

template <typename T> class Blob {
friend class BlobPtr<T>;
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
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
    data(std::make_shared<std::vector<T>>(il)) { }

template <typename T>
template <typename Iter> 
Blob<T>::Blob(Iter b, Iter e):
    data(std::make_shared<std::vector<T>>(b, e)) { }

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

template <typename T> class BlobPtr;

template <typename T> 
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> 
bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> 
bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> 
bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> 
bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> 
bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr {
friend bool operator== <T>(const BlobPtr<T>&, const BlobPtr<T>&);
friend bool operator!= <T>(const BlobPtr<T>&, const BlobPtr<T>&);
friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
friend bool operator<= <T>(const BlobPtr<T>&, const BlobPtr<T>&);
friend bool operator> <T>(const BlobPtr<T>&, const BlobPtr<T>&);
friend bool operator>= <T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, std::size_t sz = 0):
        wptr(a.data), curr(sz) { }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr& operator--();
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    if (curr == 0)
        throw std::out_of_range("decrement past beginning of BlobPtr");
    --curr;
    return *this;
}

template <typename T> 
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw std::runtime_error("Comparing BlobPtrs to different Blobs!");
    return (lhs.curr == rhs.curr);
}

template <typename T> 
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T> 
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw std::runtime_error("Comparing BlobPtrs to different Blobs!");
    return (lhs.curr < rhs.curr);
}

template <typename T> 
bool operator<=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

template <typename T> 
bool operator>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    return !(lhs <= rhs);
}

template <typename T> 
bool operator>=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    return !(lhs < rhs);
}

int main() {
    std::list<std::string> slst = {"hello", "world"};

    Blob<std::string> sb(slst.begin(), slst.end());
    BlobPtr<std::string> sbp(sb, 0);
    BlobPtr<std::string> sbp2(sb, 1);
    std::cout << (sbp < sbp2) << std::endl;

    return 0;
}