#include <ncurses.h>
#include <locale>
#include "Game.cpp"

int main() {
  // setlocale(LC_ALL, "utf8");
  // std::setlocale(LC_ALL, nullptr);
  // printf("👀");
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
