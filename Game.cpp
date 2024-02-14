#include "Global.cpp"
#include "GameObject.cpp"
#include "Window.cpp"
#include "Snake.cpp"
#include "Coordinate.cpp"
#include "Map.cpp"

class Game {
  Window window;
  Snake snake;
  Map map;

  Coordinate dir;
  
  void initialize()
  {
    // Coordinate next = snake.head() + dir;
    // if(is_one_of(map.at(next), ))            
  }
  
  void start() {
    while(true) {
      int input = window.input();
      Coordinate next = snake.head() + snake.direction;

      if(io_one_of(map.at(next), GameObjectT::Body, GameObjectT::Obstacle))
      {
        exit(0);
      }
      else if(map.at(next) == GameObjectT::Food)
      {
        snake.push(next);
        map.at()
      }
      else
      {
        snake.pop()   
      }

  
    }
  }
};