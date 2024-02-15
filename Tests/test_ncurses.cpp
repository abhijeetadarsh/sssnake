#include <ncurses.h>

int main()
{
  initscr();
  start_color();
  cbreak();
  curs_set(0);
  
  WINDOW* w = stdscr;
  // init_color(0, 1000, 200, 500);
  init_color(255, 1000, 200, 199);
  init_color(255, 10, 20, 19);
  // init_pair(3, 0, 2);
  // init_color(3, 1000, 1000, 1000);
  init_pair(5, 255, 0);
  short r, g, b;
  color_content(255, &r, &g, &b);
  printw("%d, %d, %d | ", r, g, b);
  wattron(stdscr, COLOR_PAIR(5));
  printw("hello world");
  wattroff(stdscr, COLOR_PAIR(5));
  
  getch();
  
  // while(true)
  // {
  // }
  endwin();
  return 0;
}