#include <vector>
#include "GameObject.cpp"

class Map
{
  int height, width;
  std::vector<std::vector<GameObject>> matrix;

public:
  Map(int height, int width) : height { height }, width { width }, matrix(height, width) {}
  GameObject& at(Coordinate c) { return matrix[c.y][c.x]; }

  
};

