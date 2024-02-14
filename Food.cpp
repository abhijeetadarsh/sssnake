#include <iostream>
#include "GameObject.cpp"


class Food : public GameObject
{
  int points;
  // enum Food_Type { F0, F1, F2, F3 };
  // static void 
  void type()
  {
    return GameObjectT::Food;
  }
  void consume()
  {

  }
};