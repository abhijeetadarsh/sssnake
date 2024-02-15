#ifndef COORDINATE
#define COORDINATE

class Coordinate {
 public:
  short h, w;
  bool operator==(Coordinate a) { return (a.h == h && a.w == w); }
  Coordinate() = default;
  Coordinate(short h, short w) : h(h), w(w) {}
  Coordinate operator+(const Coordinate dir) const { return { static_cast<short>(h + dir.h), static_cast<short>(dir.w + w) }; }
  Coordinate operator+=(const Coordinate dir) { h += dir.h, w += dir.w; return *this; }
  
};

static const Coordinate Up{ -1, 0 }, Down{ +1, 0 }, Left{ 0, -1 }, Right{ 0, +1 };

#endif