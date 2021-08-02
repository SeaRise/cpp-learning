#ifndef CPP_LEARNING_SCREEN_H
#define CPP_LEARNING_SCREEN_H

#include "iostream"
#include "string"
#include "vector"

class Screen {
friend class Window_mgr;

public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width+c]; }

    Screen &move(pos r, pos c);
    Screen &set(char c);
    Screen &set(pos r, pos c, char ch);

    Screen &display(std::ostream &os) {
        doDisplay(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        doDisplay(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void doDisplay(std::ostream &os) const {
        os << contents;
    }
};

inline Screen &Screen::move(pos r, pos c) {
    cursor = r*width + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r*width + c] = ch;
    return *this;
}

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

inline void Window_mgr::clear(ScreenIndex index) {
    Screen &screen = screens[index];
    screen.contents = std::string(screen.height * screen.width, ' ');
}

#endif //CPP_LEARNING_SCREEN_H
