#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <ncurses.h>
#include <sys/time.h>
#include "Global.cpp"
#include "Coordinate.cpp"
#include "GameObject_T.cpp"
#include "Input.cpp"
#include "Clock.cpp"

class GameWindow {
public:
  struct TerminalWindow {
    short _m_height, _m_width;
    WINDOW* win;
    TerminalWindow() : _m_height(LINES), _m_width(COLS)
    {
      if (_m_width % 2 == 1) { _m_width--; }
      win = newwin(_m_height, _m_width, 0, 0);
      keypad(win, true);
      nodelay(win, true);
    }
  } tw;

  short _m_height, _m_width;
  Clock _m_clock__input, _m_clock__display;

public:
  GameWindow() :
  _m_height{ static_cast<short>(tw._m_height - 2) },
  _m_width{ static_cast<short>(tw._m_width / 2 - 2) },
  _m_clock__input{ 16667 },
  _m_clock__display{ 16667 } {}

  Coordinate dimensions() { return { _m_height, _m_width }; }
  
  void set_pixel(Coordinate c, go::GameObject_T type) {
    const auto color_pair = COLOR_PAIR(static_cast<short>(type));
    wattron(tw.win, color_pair);
    wmove(tw.win, c.h + 1, c.w * 2 + 3);

    switch(type)
    {
      case go::GameObject_T::SnakeBody:
        waddstr(tw.win, go::jmp_table[3]);
        break;
      case go::GameObject_T::None:
        waddstr(tw.win, go::jmp_table[0]);
      break;
    }

    wattroff(tw.win, color_pair);
  }
  
  void refresh()
  {
    if(_m_clock__display.tick()) {
      wrefresh(tw.win);
    }
  }
  
  Input input()
  {
    if(!_m_clock__input.tick()) { return Input::NONE; }
    int input = wgetch(tw.win);
    
    switch(input)
    {
    case KEY_UP:
    case 'W':
    case 'w':
      return Input::UP;
    case KEY_DOWN:
    case 'S':
    case 's':
      return Input::DOWN;
    case KEY_LEFT:
    case 'A':
    case 'a':
      return Input::LEFT;
    case KEY_RIGHT:
    case 'D':
    case 'd':
      return Input::RIGHT;
    case '-':
      return Input::DECREMENT_LENGTH;
    case '=':
      return Input::INCREMENT_LENGTH;
    case '1':
      return Input::SPEED_1;
    case '2':
      return Input::SPEED_2;
    case '3':
      return Input::SPEED_3;
    case ' ':
      return Input::PLAY__PAUSE;
    
    default:
      return Input::NONE;
    }
  }
};

#endif