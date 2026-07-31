/*
Define your own versions of Screen and Window_mgr in which
clear is a member of Window_mgr and a friend of Screen.
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Screen;

class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        Window_mgr(); // will declare later once we can actually talk about screens
        void clear(ScreenIndex);
        void printAll();
        std::vector<Screen> screens; // public for now because i need it for demo
};

class Screen {
    public:
        friend void Window_mgr::clear(Window_mgr::ScreenIndex);
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(pos ht, pos wd):
            height(ht), width(wd), contents(ht * wd, ' ') { }
        Screen(pos ht, pos wd, char c):
            height(ht), width(wd), contents(ht * wd, c) { }
        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; }
        Screen &move(pos r, pos c) { cursor = r * width + c; return *this; }
        Screen &set(char c) { contents[cursor] = c; return *this; }
        Screen &set(pos r, pos c, char ch) { contents[r*width+c] = ch; return *this; }
        Screen &display(std::ostream &ost) { do_display(ost); return *this; }
        const Screen &display(std::ostream &ost) const { do_display(ost); return *this; }
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

Window_mgr::Window_mgr() : screens{Screen(3, 3, '-')} {}

void Window_mgr::clear(Window_mgr::ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, '-');
}

void Window_mgr::printAll() {
    for (Screen &s : screens) {
        s.display(cout);
        cout << endl;
    }
}

int main() {
    Window_mgr wm = Window_mgr();
    wm.printAll();

    wm.screens[0].move(1, 1).set('X');
    wm.printAll();

    wm.screens[0].move(0, 2).set('O');
    wm.printAll();

    wm.screens[0].move(1, 2).set('X');
    wm.printAll();

    wm.clear(0);
    wm.printAll();
}
