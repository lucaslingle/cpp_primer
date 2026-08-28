/*
Add a move constructor and move-assignment operator to your `String` class.
*/

#include <iostream>
#include <cstring>
#include <cstddef>
#include <memory>
using std::cout;
using std::endl;
using std::strlen;
using std::size_t;
using std::allocator;

class String {
    public:
        String() { }
        String(const char *p);
        String(const String &s);
        String& operator=(const String &rhs);
        String(String &&s) noexcept;
        String& operator=(String &&rhs) noexcept;
        ~String();
        size_t size() const { return first_free - elements; }
        char operator[](size_t ix) const { return elements[ix]; }
    private:
        static allocator<char> alloc;
        char *elements = nullptr;
        char *first_free = nullptr;
        char *cap = nullptr;
        void free();
};

allocator<char> String::alloc;

void String::free() {
    if (elements) {
        while (first_free != elements)
            alloc.destroy(--first_free);
        alloc.deallocate(elements, cap - elements);
    }
}

String::String(const char *p) {
    auto n = strlen(p);
    auto q = alloc.allocate(n);
    elements = q;

    while (*p)
        alloc.construct(q++, *p++);
    first_free = q;
    cap = q;
}

String::String(const String& s) {
    // cout << "Running copy constructor" << endl;

    auto n = s.size();
    auto q = alloc.allocate(n);
    elements = q;

    for (size_t i = 0; i != n; ++i)
        alloc.construct(q++, s[i]);
    first_free = q;
    cap = q;
}

String& String::operator=(const String &rhs) {
    // cout << "Running copy-assignment operator" << endl;

    auto n = rhs.size();
    auto q = alloc.allocate(n);

    auto new_elements = q;
    for (size_t i = 0; i != n; ++i)
        alloc.construct(q++, rhs[i]);
    auto new_first_free = q;
    auto new_cap = q;

    free();
    elements = new_elements;
    first_free = new_first_free;
    cap = new_cap;
    return *this;
}

String::String(String &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
        s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(String &&s) noexcept {
    if (this == &s)
        return *this;

    free();
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;
    s.elements = s.first_free = s.cap = nullptr;
    return *this;
}

String::~String() {
    free();
}
