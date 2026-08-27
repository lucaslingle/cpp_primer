/*
Write a class named `String` that is a simplified version of the library 
`string` class. Your class should have at least a default constructor
and a constructor that takes a pointer to a C-style string.
Use an `allocator` to allocate memory that your string class uses.
*/

#include <cstring>
#include <cstddef>
#include <memory>
using std::strlen;
using std::size_t;
using std::allocator;

class String {
    public:
        String() { }
        String(const char *p);
        String(const String &s);
        String& operator=(const String &rhs);
        ~String();
        size_t size() const { return first_free - elements; }
        char operator[](size_t ix) const { return elements[ix]; }
    private:
        static allocator<char> alloc;
        char *elements = nullptr;
        char *first_free = nullptr;
        char *cap = nullptr;
};

allocator<char> String::alloc;

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
    auto n = s.size();
    auto q = alloc.allocate(n);
    elements = q;

    for (size_t i = 0; i != n; ++i)
        alloc.construct(q++, s[i]);
    first_free = q;
    cap = q;
}

String& String::operator=(const String &rhs) {
    auto n = rhs.size();
    auto q = alloc.allocate(n);

    auto new_elements = q;
    for (size_t i = 0; i != n; ++i)
        alloc.construct(q++, rhs[i]);
    auto new_first_free = q;
    auto new_cap = q;

    if (elements) {
        while (first_free != elements)
            alloc.destroy(--first_free);
        alloc.deallocate(elements, cap - elements);
    }

    elements = new_elements;
    first_free = new_first_free;
    cap = new_cap;
    return *this;
}

String::~String() {
    if (elements) {
        while (first_free != elements)
            alloc.destroy(--first_free);
        alloc.deallocate(elements, cap - elements);
    }
}
