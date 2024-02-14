#include <iostream>
#include "Global.cpp"

int main()
{
  char c = '9';
  std::cout << is_one_of(c, 'b', 'c', '5', '8', '0') << "\n";
  return 0;
}