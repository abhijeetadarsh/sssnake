#include <ncurses.h>
#include <locale>
#include "Game.cpp"

int main() {

  initscr();
  start_color();
  curs_set(0);
  cbreak();
  noecho();

  go::initialize_color_pairs();
  
  GameWindow window;
  Map map(window.dimensions());

  Game g(window, map);
  g.initialize();
  g.start();
  
  endwin();
  return 0;
}
