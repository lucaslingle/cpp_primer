// this version really does work, just like i said in exercise 13.57.cc

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::sort;

class Foo {
    public:
        Foo() = default;
        void push_back(int item) { data.push_back(item); }
        void print() {
            for (auto i : data)
                cout << i << " ";
            cout << endl;
        }
        Foo sorted() &&;
        Foo sorted() const &;
    private:
        vector<int> data;
};

Foo Foo::sorted() && {
    cout << "rvalue reference qualified sort" << endl;
    sort(data.begin(), data.end());
    return *this;
}

// Foo Foo::sorted() const & {
//     cout << "lvalue reference qualified sort (loopy)" << endl;
//     Foo ret(*this);
//     return ret.sorted();
// }

Foo Foo::sorted() const & { 
    cout << "lvalue reference qualified sort (non-loopy)" << endl;
    return Foo(*this).sorted(); 
}

int main() {
    Foo foo = Foo();
    foo.push_back(10);
    foo.push_back(9);
    foo.push_back(8);
    foo.sorted();
    foo.print();
}