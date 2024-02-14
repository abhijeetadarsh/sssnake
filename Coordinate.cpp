#ifndef COORDINATE
#define COORDINATE

class Coordinate {
 public:
  int h, w;
  bool operator==(Coordinate a) { return (a.h == h && a.w == w); }
  Coordinate(int h, int w) x(h), y(w) {}
  Coordinate operator+(Coordinate dir) { return { h + dir.h, x + dir.w + w }; }
  
};

static const Coordinate Up{ -1, 0 }, Down{ +1, 0 }, Left{ 0, -1 }, Right{ 0, +1 };

#endif