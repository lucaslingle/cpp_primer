#include <cstddef>
#include <memory>
#include <utility>
using std::size_t;
using std::allocator;
using std::uninitialized_copy;
using std::pair;

template <typename T> class Vec;
template <typename T> bool operator==(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T> bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs);

template <typename T> class Vec {
friend bool operator== <T>(const Vec<T> &lhs, const Vec<T> &rhs);
friend bool operator!= <T>(const Vec<T> &lhs, const Vec<T> &rhs);
public:
    Vec(): 
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    Vec(const Vec &);
    Vec& operator=(const Vec &);
    ~Vec();
    void push_back(const T &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T* begin() const { return elements; }
    T* end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t n, const T& t = T());
    template <typename... Args> void emplace_back(Args&&...); 
private:
    static allocator<T> alloc;
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    pair<T*, T*> alloc_n_copy(const T *, const T *);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};

template <typename T> 
allocator<T> Vec<T>::alloc;

template <typename T>
void Vec<T>::push_back(const T &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec &v) {
    auto data = alloc_n_copy(v.begin(), v.end());
    elements = data.first;
    first_free = data.second;
    cap = data.second;
}

template <typename T>
Vec<T>::~Vec() {
    free();
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    reserve(newcapacity);
}

template <typename T>
void Vec<T>::reserve(size_t n) {
    if (n <= capacity())
        return;
    auto newcapacity = n;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::resize(size_t n, const T& t) {
    if (n > size()) {
        reserve(n);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, t);
    } else {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    }
}

template <typename T>
template <typename... Args>
void Vec<T>::emplace_back(Args&&... args) {
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
inline bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
    // decision: say equal if contents are, even if ptrs differ
    if (lhs.size() != rhs.size())
        return false;
    for (auto elem = lhs.elements, elem2 = rhs.elements; elem != lhs.first_free; ++elem, ++elem2)
        if (*elem != *elem2)
            return false;
    return true;
}

template <typename T>
inline bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs == rhs);
}
