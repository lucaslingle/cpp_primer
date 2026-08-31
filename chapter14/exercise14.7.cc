/*
Define an output operator for the `String` class 
you wrote for the exercises on p. 531 (exercise 13.44).
*/

#include <cstring>
#include <cstddef>
#include <memory>
#include <iostream>
using std::strlen;
using std::size_t;
using std::allocator;
using std::ostream;

class String {
    friend ostream& operator<<(ostream&, const String&);
    public:
        String() { }
        String(const char *p);
        String(const String &s);
        String& operator=(const String &rhs);
        ~String();
        size_t size() const { return first_free - elements; }
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
    auto p = s.elements;

    for (size_t i = 0; i != n; ++i)
        alloc.construct(q++, *p++);
    first_free = q;
    cap = q;
}

String& String::operator=(const String &rhs) {
    auto n = rhs.size();
    auto q = alloc.allocate(n);
    auto p = rhs.elements;

    auto new_elements = q;
    for (size_t i = 0; i != n; ++i)
        alloc.construct(q++, *p++);
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

ostream& operator<<(ostream& ost, const String &s) {
    for (auto elem = s.elements; elem != s.first_free; ++elem)
        ost << *elem;
    return ost;
}
