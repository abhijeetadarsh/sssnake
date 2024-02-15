#include <iostream>
// #include "Global.cpp"
#include <ncurses.h>

int main()
{
  initscr();

  WINDOW* w = stdscr;
  start_color();

  init_pair(2, COLOR_RED, COLOR_GREEN);
  wattron(w, A_BOLD | A_UNDERLINE | A_ITALIC | COLOR_PAIR(2));
  wprintw(w, "hello world!!");

  getch();
  init_pair(2, COLOR_BLACK, COLOR_YELLOW);
  wattron(w, A_BOLD | A_UNDERLINE | A_ITALIC | COLOR_PAIR(2));
  wprintw(w, "hola world!!");

  getch();
  // char c = '9';
  // std::cout << is_one_of(c, 'b', 'c', '5', '8', '0') << "\n";
  // printf("%s%s", "🍃", "🟢");
  endwin();
  return 0;
}