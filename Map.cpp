#ifndef MAP
#define MAP

#include <vector>
#include <cstdlib>
#include <cassert>
#include "GameObject_T.cpp"
#include "Coordinate.cpp"
#include "Snake.cpp"

class Map
{
  short height, width;
  std::vector<std::vector<go::GameObject_T>> grid;

public:
  Map(Coordinate dim) : height { dim.h }, width { dim.w }, grid(height, std::vector<go::GameObject_T> (width)) {}
  go::GameObject_T& at(const Coordinate c) { return grid[c.h][c.w]; }
  
  Snake generate_snake_and_direction()
  {
    Snake s { Right };
    constexpr short length = 10;
    printf("%d, %d\n", length, width - 1);
    assert(length < width - 1);
    s.push_head({ static_cast<short>(height / 2), static_cast<short>((width - length) / 2) });
    for(short i_len = 1; i_len < length; i_len++) { s.push_head(s.next()); }
    return s;
  }
  bool is_valid(const Coordinate c) { return (0 <= c.h && c.h < height && 0 <= c.w && c.w < width); }
};

#endif