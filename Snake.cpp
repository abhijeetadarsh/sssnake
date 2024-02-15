#ifndef SNAKE
#define SNAKE
#include <queue>
#include "Coordinate.cpp"

class Snake {
private:
  std::deque<Coordinate> _m_body;
  Coordinate _m_direction;
public:
  Snake() = default;
  Snake(Coordinate direction) : _m_body{}, _m_direction{ direction } {}
  ~Snake() = default;

  Coordinate head() { return _m_body.front();  }
  Coordinate tail() { return _m_body.back(); }
  
  const std::deque<Coordinate>& body() { return _m_body; }
  Coordinate direction() { return _m_direction; }
  Coordinate next() { return _m_body.front() + _m_direction; }
  short length() { return static_cast<short>(_m_body.size()); }
  
  void push_head(const Coordinate c) { _m_body.push_front(c); }
  void pop_tail() { _m_body.pop_back(); }

  void change_direction(const Coordinate direction) { _m_direction = direction; }
  
};

#endif