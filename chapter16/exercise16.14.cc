/*
Write a `Screen` class template that uses nontype parameters
to define the height and width of the `Screen`.
*/

#include <string>
#include <cstddef>

template <std::size_t Height, std::size_t Width>
class Screen {
public:
    typedef std::size_t pos;
    Screen(): contents(Height * Width, ' ') { }
    Screen(char c): contents(Height * Width, c) { }
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * Width + c]; }
    Screen& navigate(pos r, pos c) { cursor = r * Width + c; return *this; }
private:
    pos cursor = 0;
    std::string contents;
};
