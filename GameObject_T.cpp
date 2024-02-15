#ifndef GAME_OBJECT_T
#define GAME_OBJECT_T

#include <ncurses.h>
#include <map>

namespace go
{
  enum class GameObject_T : char { None = 0, Food, Obstacle, SnakeBody };

  // std::map<GameObject_T

  const char* jmp_table[] =
  {
    "  ",
    "",
    "",
    "++"
  };
  
  void initialize_color_pairs()
  {
    init_pair(static_cast<short>(GameObject_T::None), COLOR_BLACK, COLOR_BLACK);
    // init_pair(static_cast<short>(GameObject_T::Food), COLOR_WHITE, )
    init_pair(static_cast<short>(GameObject_T::SnakeBody), COLOR_RED, COLOR_RED);
  }
}

#endif