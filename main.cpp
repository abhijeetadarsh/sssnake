#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <locale>
#include <queue>

#define RED 1
#define GREEN 2
#define BLACK 3
#define YELLOW 4

int get_terminal_size(int* cols, int* rows) {
  struct winsize ws;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
    return -1;  // Error occurred
  }

  *cols = ws.ws_col;
  *rows = ws.ws_row;
  return 0;  // Success
}

// getmaxyx


int main() {
  initscr();

  // Snake sss;
  // sss.start();
  // while (true) {
  //   usleep(200000);
  //   sss.getinput();
  //   sss.move();
  // }
  endwin();
  return 0;
}
