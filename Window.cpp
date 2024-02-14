#include <ncurses.h>
#include "Global.cpp"
#include "Coordinate.cpp"
#include "Pixel.cpp"

class Window {
  struct TerminalWindow {
    int height, width;
    WINDOW* win;
    TerminalWindow() : height(LINES), width(COLS)
    {
      if (width % 2 == 1) { width--; }
      win = newwin(height, width, 0, 0);
    }
  } tw;

  int height, width;

public:
  Window() : height{ tw.height - 2 }, width{ tw.width / 2 - 2 } {}

  void set(Pixel c) {
    // for (int i = 0; i < c.width; i++) {
    //   attron(COLOR_PAIR(c.contents[i].color_pair));
    //   mvwaddch(tw.win, c.y + 1, c.x * 2 + i + 2, c.contents[i].value);
    //   attroff(COLOR_PAIR(c.contents[i].color_pair));
    // }
  }
  
  void refresh() { wrefresh(tw.win); }
  
  Coordinate input()
  {
    int input = wgetch(tw.win);

    if (is_one_of(input, KEY_UP, 'W', 'w')) {
      return Up;
    } else if (is_one_of(input, KEY_DOWN, 'S', 's')) {
      return Down;
    } else if (is_one_of(input, KEY_LEFT, 'D', 'd')) {
      return Left;
    } else if (is_one_of(input, KEY_RIGHT, 'A', 'a')) {
      return Right;
    }
  }
};