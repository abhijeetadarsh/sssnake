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
  short _m_height, _m_width;
  std::vector<std::vector<go::GameObject_T>> grid;

public:
  Map(Coordinate dim) : _m_height { dim.h }, _m_width { dim.w }, grid(_m_height, std::vector<go::GameObject_T> (_m_width)) {}
  go::GameObject_T& at(const Coordinate c) { return grid[c.h][c.w]; }
  
  Snake generate_snake_and_direction()
  {
    Snake s { Right };
    constexpr short length = 40;
    // printf("%d, %d\n", length, width - 1);
    assert(length < _m_width - 1);
    s.push_head({ static_cast<short>(_m_height / 2), static_cast<short>((_m_width - length) / 2) });
    for(short i_len = 1; i_len < length; i_len++) { s.push_head(s.next()); }
    return s;
  }
  bool is_valid(const Coordinate c) { return (0 <= c.h && c.h < _m_height && 0 <= c.w && c.w < _m_width); }
};

#endif