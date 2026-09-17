/*
Implement input and output operators for your `Screen` template.
Which if any friends are necessary in class `Screen` to make the input
and output operators work? 

Explain why each friend declaration, if any, was needed.
*/

#include <iostream>
#include <string>
#include <cstddef>

// I made both operators `operator<< <H, W>` and `operator>> <H, W>` friends
// of the class `Screen<H, W>`. Both access private data member `contents`.
// Note that it is possible for operator<< to call get(r, c) instead 
// but this incurs function call overhead for every character of the H * W.

template <std::size_t H, std::size_t W> class Screen;

template <std::size_t H, std::size_t W>
std::ostream& operator<<(std::ostream &ost, const Screen<H, W> &screen);

template <std::size_t H, std::size_t W>
std::istream& operator>>(std::istream &ist, Screen<H, W> &screen);

template <std::size_t H, std::size_t W>
class Screen {
friend std::ostream& operator<< <H, W>(std::ostream &, const Screen<H, W> &);
friend std::istream& operator>> <H, W>(std::istream &, Screen<H, W> &);
public:
    typedef std::size_t pos;
    Screen(): contents(H * W, ' ') { }
    Screen(char c): contents(H * W, c) { }
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * W + c]; }
    Screen& navigate(pos r, pos c) { cursor = r * W + c; return *this; }
private:
    pos cursor = 0;
    std::string contents;
};

template <std::size_t H, std::size_t W>
std::ostream& operator<<(std::ostream &ost, const Screen<H, W> &screen) { 
    for (typename Screen<H, W>::pos ix = 0; ix != H * W; ++ix) {   
        ost << screen.contents[ix]; 
        if ((ix + 1) % W == 0)
            ost << '\n';
    }
    return ost;
}

template <std::size_t H, std::size_t W>
std::istream& operator>>(std::istream &ist, Screen<H, W> &screen) { 
    for (typename Screen<H, W>::pos ix = 0; ix != H * W; ++ix)
        screen.contents[ix] = ist.get();
    return ist;
}
