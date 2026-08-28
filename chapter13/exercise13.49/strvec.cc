/*
Add a move constructor and move-assignment operator to your 
`StrVec` class.
*/

#include <cstddef>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>
using std::size_t;
using std::string;
using std::allocator;
using std::uninitialized_copy;
using std::pair;
using std::initializer_list;
using std::for_each;

class StrVec {
    public:
        StrVec(): 
            elements(nullptr), first_free(nullptr), cap(nullptr) { }
        StrVec(initializer_list<string> il);
        StrVec(const StrVec &);
        StrVec& operator=(const StrVec &);
        StrVec(StrVec &&) noexcept;
        StrVec& operator=(StrVec &&) noexcept;
        ~StrVec();
        void push_back(const string &);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        string *begin() const { return elements; }
        string *end() const { return first_free; }
        void reserve(size_t);
        void resize(size_t, const string &s = string());
    private:
        static allocator<string> alloc;
        void chk_n_alloc() {
            if (size() == capacity())
                reallocate();
        }
        pair<string*, string*> alloc_n_copy(const string *, const string *);
        void free();
        void reallocate();
        string *elements;
        string *first_free;
        string *cap;
};

allocator<string> StrVec::alloc;

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> 
StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(initializer_list<string> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    elements = data.first;
    first_free = data.second;
    cap = data.second;
}

StrVec::StrVec(const StrVec &sv) {
    auto data = alloc_n_copy(sv.begin(), sv.end());
    elements = data.first;
    first_free = data.second;
    cap = data.second;
}

StrVec::StrVec(StrVec &&sv) noexcept 
    : elements(sv.elements), first_free(sv.first_free), cap(sv.cap) {
        sv.elements = sv.first_free = sv.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&sv) noexcept {
    if (this == &sv)
        return *this;

    free();
    elements = sv.elements;
    first_free = sv.first_free;
    cap = sv.cap;
    sv.elements = sv.first_free = sv.cap = nullptr;
    return *this;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    reserve(newcapacity);
}

void StrVec::reserve(size_t n) {
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

void StrVec::resize(size_t n, const string &s) {
    if (n > size()) {
        reserve(n);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, s);
    } else {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    }
}
