#ifndef PIXEL
#define PIXEL

#include <ncurses.h>
#include "Coordinate.cpp"

class Pixel {
  Coordinate c;
  struct Content {
    int value;
    int color_pair;
  } contents[2];
  int width;
  // Pixel() {}
};

#endif