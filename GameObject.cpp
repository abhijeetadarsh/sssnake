#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "Pixel.cpp"

enum class GameObjectT { None, Food, Obstacle, Body };

class GameObject
{
  virtual bool interact() = 0;
};

#endif