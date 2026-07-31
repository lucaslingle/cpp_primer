/*
Give your Screen class three consrtuctors: a default constructor;
a constructor that takes values for height and width and 
initializes the contents to hold the given number of blanks;
and a constructor that takes values for height, width, and character 
to use as the contents of the creen.
*/

#include <string>

class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd):
        height(ht), width(wd), contents(ht * wd, ' ') { }
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
