#include <ncurses.h>
#include <locale>
int main()
{
  printf("🍺");
  // getch();
  getchar();

  std::setlocale(LC_CTYPE, "");
  initscr();
  // cchar_t c = L'🍺';
  wprintw(stdscr, "🍺\0");
  // wadd_wch()
  getch();

  endwin();
  return 0;
}