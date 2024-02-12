// ██████████████████████████████████████████████████
/*
initscr();  // Initialize ncurses, allocate memory and clears the screen
if (!has_colors()) {
  printw("Terminal does not support color");
  getch();
  return -1;
}
start_color();  // Enable color
init_pair(1, COLOR_GREEN, COLOR_BLACK);

int height = 25, width = 50, start_y = 0, start_x = 0;
get_terminal_size(&width, &height);

WINDOW* my_win = newwin(height, width, start_y, start_x);

// box(my_win, 0, 0);
int left, right, top, bottom, tlc, trc, blc, brc;
left = right = ACS_CKBOARD;
top = bottom = ACS_CKBOARD;
tlc = ACS_CKBOARD;
trc = ACS_CKBOARD;
blc = ACS_CKBOARD;
brc = ACS_CKBOARD;

if (can_change_color()) {
  init_color(COLOR_CYAN, 0, 0, 0);
  #define DC 255
  init_color(DC, 999, 999, 999);
  init_pair(2, COLOR_CYAN, DC);

  wattron(my_win, COLOR_PAIR(2));
  mvwprintw(my_win, 20, 10, "can change color");
  wattroff(my_win, COLOR_PAIR(2));
  refresh();
  wrefresh(my_win);
  getch();
}
wattron(my_win, COLOR_PAIR(1));
wborder(my_win, left, right, top, bottom, tlc, trc, blc, brc);
mvwprintw(my_win, 10, 10, "Hello World!");
wattroff(my_win, COLOR_PAIR(1));

refresh();
wrefresh(my_win);
getch();
endwin();  // deallocates the memory and end ncurses
*/