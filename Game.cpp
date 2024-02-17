#ifndef GAME
#define GAME

#include <cstdlib>
#include <unistd.h>
#include <sys/time.h>
#include "Global.cpp"

#include "Input.cpp"
#include "GameObject_T.cpp"
#include "GameWindow.cpp"
#include "Snake.cpp"
#include "Coordinate.cpp"
#include "Map.cpp"
#include "GameConfig.cpp"


class Game {
  GameWindow _m_window;
  Map _m_map;
  Snake _m_snake;

  GameConfig _m_config;

public:
  Game(GameWindow window, Map map) : _m_window(window), _m_map(map), _m_snake{ map.generate_snake_and_direction() } {}
  // Game(GameWindow window, Map map, Snake snake, Coordinate direction) : _m_window(window), _m_map(map), _m_snake(snake), _m_snake_direction(direction) {}
  
  void initialize()
  {
    for(const auto coordinate : _m_snake.body())
    {
      _m_window.set_pixel(coordinate, go::GameObject_T::SNAKE_BODY);
      _m_map.at(coordinate) = go::GameObject_T::SNAKE_BODY;
    }
    _m_window.refresh();         
  }
  
  void start() {
    while(true) { // game logic
      update(_m_window.input());
      _m_window.refresh();
      usleep(30000);
    }
  }
  void update(const Input input)
  {
    if(!_m_config._m_clock.tick())
    {
      if(input != Input::NONE) { printw("@"); refresh(); _m_window.replay_last_input(); }
      return;
    }

    if(_m_config.is_paused())
    {
      if(input == Input::PLAY__PAUSE) {
        _m_config.toggle_play_pause();
      }

      return;
    }

    if(is_one_of(input, Input::UP, Input::DOWN, Input::LEFT, Input::RIGHT)) {
      change_direction(input);
    }
    // else 
    const Coordinate next = _m_snake.next();

    if(!_m_map.is_valid(next) || is_one_of(_m_map.at(next), go::GameObject_T::SNAKE_BODY, go::GameObject_T::OBSTACLE)) {
      game_over();
      return;
    }
    
    _m_snake.push_head(next);
    _m_window.set_pixel(next, go::GameObject_T::SNAKE_BODY);

    if(_m_map.at(next) == go::GameObject_T::NONE)
    {
      _m_window.set_pixel(_m_snake.tail(), go::GameObject_T::NONE);
      _m_map.at(_m_snake.tail()) = go::GameObject_T::NONE;
      _m_snake.pop_tail();
    } 
  }
  void game_over()
  {
    wprintw(_m_window.tw.win, "GAME OVER!");
    wrefresh(_m_window.tw.win);
    exit(0);
  }
  void handle_input(Input input)
  {
    if(is_one_of(input, Input::LEFT, Input::RIGHT, Input::UP, Input::DOWN))
    {
      change_direction(input);
    }
  }
  void change_direction(Input input)
  {
    Coordinate final_direction;

    switch(input)
    {
    case Input::UP:
      final_direction = Up;
      break;
    case Input::DOWN:
      final_direction = Down;
      break;
    case Input::LEFT:
      final_direction = Left;
      break;
    case Input::RIGHT:
      final_direction = Right;
      break;
    default:
      break;
    }

    if(final_direction + _m_snake.direction() == Coordinate { 0, 0 }) {
      return;
    }

    _m_snake.change_direction(final_direction);
  }
};

#endif