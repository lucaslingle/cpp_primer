/*
Write your own version of the Screen class.
*/

#include <string>

class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht * wd, c) { }
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    Screen &move(pos r, pos c) { cursor = r * width + c; return *this; }
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
};
