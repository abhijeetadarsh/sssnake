#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <locale>
#include <queue>
// #include <bits/stdc++.h>
// #include <utility>
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

class Snake {
 private:
  class Coordinate {
   public:
    int x, y;
    // int color = COLOR_RED;
    bool operator==(Coordinate a) {
      return (a.x == x && a.y == y);
    }
    Coordinate(int p, int q) : x(p), y(q) {}
    // Coordinate(int p, int q, int c) : Coordinate(p, q) { color = c; }
  };

  std::deque<Coordinate> body;
  int height = 25, width = 50, start_y = 0, start_x = 0;
  int x_max = width / 2 - 3, y_max = height - 3;
  WINDOW* win;
  bool in_range(Coordinate &c) {
    return (0 <= c.x && c.x <= x_max && 0 <= c.y && c.y <= y_max);
  }
  bool is_valid_food(Coordinate &c) {
    if(!in_range(c)) return false;
    for(auto a: body) {
      if(a == c) return false;
    }
    return true;
  }
  Coordinate generateRandomCoordinate() {
    srand(time(nullptr));  // Seed the random number generator
    Coordinate c(-1,-1);
    while(!is_valid_food(c)) {
      c.x = rand() % (x_max + 1);
      c.y = rand() % (y_max + 1);
    }
    return c;
  }

 public:
  Snake() {
    initscr();

    start_color();
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);

    get_terminal_size(&width, &height);
    win = newwin(height, width, start_y, start_x);

    nodelay(win, TRUE);
    keypad(win, TRUE);
    curs_set(0);
    noecho();

    body.emplace_back(11, 21);
    body.emplace_back(11, 22);
    body.emplace_back(11, 23);
    body.emplace_back(11, 24);
    body.emplace_back(10, 24);
    body.emplace_back(10, 25);
    body.emplace_back(10, 26);
    body.emplace_back(10, 27);
    body.emplace_back(10, 28);
    body.emplace_back(10, 29);
    body.emplace_back(10, 30);
    body.emplace_back(10, 31);
  }

  ~Snake() {
    delwin(win);
    endwin();
  }

  void put_char(Coordinate c, int ch, int color) {
    wattron(win, COLOR_PAIR(color));
    mvwaddch(win, c.y + 1, c.x * 2 + 2, ch);
    mvwaddch(win, c.y + 1, c.x * 2 + 3, ch);
    wattroff(win, COLOR_PAIR(color));
  }
  void start() {
    box(win, 0, 0);
    bool is_head = true;
    for (auto c : body) {
      if (is_head) {
        put_char(c, ACS_CKBOARD, RED);
        is_head = false;
      } else {
        put_char(c, ACS_CKBOARD, GREEN);
      }
    }
    Coordinate food = generateRandomCoordinate();
    put_char(food,ACS_DIAMOND,YELLOW);
    wrefresh(win);
  }
  void move_snake(char direction) {
    auto [x, y] = body.front();
    int x_next, y_next;
    if (direction == 'a') {  // move up
      x_next = x - 1, y_next = y;
    } else if (direction == 'w') {  // move left
      x_next = x, y_next = y - 1;
    } else if (direction == 'd') {  // move down
      x_next = x + 1, y_next = y;
    } else if (direction == 's') {  // move right
      x_next = x, y_next = y + 1;
    } else {
      return;
    }
    if (0 <= x_next && x_next <= x_max && 0 <= y_next &&
        y_next <= y_max) {
      Coordinate head(x_next, y_next), tail(body.back()), neck(body.front());
      body.emplace_front(x_next, y_next);
      body.pop_back();
      put_char(head, ACS_CKBOARD, RED);
      put_char(neck, ACS_CKBOARD, GREEN);
      put_char(tail, ' ', BLACK);
      wrefresh(win);
    }
  }
  void getinput() {
    char direction = wgetch(win);
    if (direction == -1) {
      // return;
      Coordinate head(body[0]), neck(body[1]);
      if (head.x == neck.x) {
        if (head.y < neck.y) {
          move_snake('w');
        } else {
          move_snake('s');
        }
      } else {
        if (head.x < neck.x) {
          move_snake('a');
        } else {
          move_snake('d');
        }
      }
    } else {
      move_snake(direction);
    }
  }
};

int main() {
  Snake sss;
  sss.start();
  while (true) {
    usleep(200000);
    sss.getinput();
  }
  return 0;
}
