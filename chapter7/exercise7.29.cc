/*
Revise your Screen class so that move, set, and display functions 
return Screen instead of Screen &, and check your prediction 
from the previous exercise.
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;

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
    Screen move(pos r, pos c) { cursor = r * width + c; return *this; }
    Screen set(char c) { contents[cursor] = c; return *this; }
    Screen set(pos r, pos c, char ch) { contents[r*width+c] = ch; return *this; }
    Screen display(std::ostream &ost) { do_display(ost); return *this; }
    const Screen display(std::ostream &ost) const { do_display(ost); return *this; }
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
    void do_display(std::ostream &ost) const { 
        for (pos ix = 0; ix != height * width; ++ix) {   
            ost << contents[ix]; 
            if ((ix + 1) % width == 0)
                ost << '\n';
        }
    }
};

int main() {
    Screen myScreen = Screen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";

    // output this time will be
    
    // XXXXX
    // XXXXX
    // XXXXX
    // XXXXX
    // #XXXX

    // XXXXX
    // XXXXX
    // XXXXX
    // XXXXX
    // XXXXX
}
