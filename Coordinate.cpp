#ifndef COORDINATE
#define COORDINATE

class Coordinate {
 public:
  short h, w;
  Coordinate() = default;
  Coordinate(short h, short w) : h(h), w(w) {}
  Coordinate operator+(const Coordinate rhs) const { return { static_cast<short>(h + rhs.h), static_cast<short>(rhs.w + w) }; }
  Coordinate operator+=(const Coordinate rhs) { h += rhs.h, w += rhs.w; return *this; }
  bool operator==(const Coordinate rhs) { return (h == rhs.h && w == rhs.w); }
  bool operator!=(const Coordinate rhs) { return !(operator==(rhs)); }
  
};

static const Coordinate Up{ -1, 0 }, Down{ +1, 0 }, Left{ 0, -1 }, Right{ 0, +1 };

#endif