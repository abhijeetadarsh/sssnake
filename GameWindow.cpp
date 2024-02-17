#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <ncurses.h>
#include <sys/time.h>
#include "Global.cpp"
#include "Coordinate.cpp"
#include "GameObject_T.cpp"
#include "Input.cpp"
#include "ClockGuard.cpp"

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
  ClockGuard _m_clock__input, _m_clock__display;

  Input _m_last_input { Input::NONE };
  bool _m_replay_last_input{ false };

public:
  GameWindow() :
  _m_height{ static_cast<short>(tw._m_height - 2) },
  _m_width{ static_cast<short>(tw._m_width / 2 - 2) },
  _m_clock__input{ 166667 },
  _m_clock__display{ 166667 } {}

  Coordinate dimensions() { return { _m_height, _m_width }; }
  
  void set_pixel(Coordinate c, go::GameObject_T type) {
    const auto color_pair = COLOR_PAIR(static_cast<short>(type));
    wattron(tw.win, color_pair);
    wmove(tw.win, c.h + 1, c.w * 2 + 3);

    switch(type)
    {
      case go::GameObject_T::SNAKE_BODY:
        waddstr(tw.win, go::jmp_table[3]);
        break;
      case go::GameObject_T::NONE:
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
    
    if(_m_replay_last_input)
    {
      _m_replay_last_input = false;
      return _m_last_input;
    }
    
    int input = wgetch(tw.win);
    
    Input ret;
    
    switch(input)
    {
    case KEY_UP:
    case 'W':
    case 'w':
      ret =  Input::UP;
      break;
    case KEY_DOWN:
    case 'S':
    case 's':
      ret = Input::DOWN;
      break;
    case KEY_LEFT:
    case 'A':
    case 'a':
      ret = Input::LEFT;
      break;
    case KEY_RIGHT:
    case 'D':
    case 'd':
      ret = Input::RIGHT;
      break;
    case '-':
      ret = Input::DEC_LEN;
      break;
    case '=':
      ret = Input::INC_LEN;
      break;
    case '1':
      ret = Input::SPEED_1;
      break;
    case '2':
      ret = Input::SPEED_2;
      break;
    case '3':
      ret = Input::SPEED_3;
      break;
    case ' ':
      ret = Input::PLAY__PAUSE;
      break;
    default:
      ret = Input::NONE;
      break;
    }
    
    _m_last_input = ret;
    return ret;
  }

  void replay_last_input() { _m_replay_last_input = true; }
};

#endif