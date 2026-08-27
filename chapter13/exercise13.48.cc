/*
Define a `vector<String>` and call `push_back` several times on that vector.
Run your program and see how often `Strings` are copied.
*/

// with four push_backs, i get seven calls to copy-constructor.
// with five push_backs, i get twelve calls to the copy-constructor.
//
// a reallocation must have occurred for the fifth push-back, 
// resulting in four copied elements and then one copy for the new element. 
//
// no copy assignment operations occurred.

#include <iostream>
#include <cstring>
#include <cstddef>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::strlen;
using std::size_t;
using std::allocator;
using std::vector;

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
    cout << "Running copy constructor" << endl;

    auto n = s.size();
    auto q = alloc.allocate(n);
    elements = q;

    for (size_t i = 0; i != n; ++i)
        alloc.construct(q++, s[i]);
    first_free = q;
    cap = q;
}

String& String::operator=(const String &rhs) {
    cout << "Running copy-assignment operator" << endl;

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

int main() {
    vector<String> svec;
    svec.push_back(String("Hello"));
    svec.push_back(String("World"));
    svec.push_back(String("Greetings"));
    svec.push_back(String("Planet"));
    svec.push_back(String("Earth"));

    return 0;
}