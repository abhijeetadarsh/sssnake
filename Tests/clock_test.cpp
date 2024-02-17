#include <cstdio>
#include "../ClockGuard.cpp"
#include <unistd.h>

int main()
{
  int cnt = 0;
  ClockGuard c { 100000 };

  while(true) {
    if(c.tick()) {
      printf("hello %d\n", cnt++);
    }
    usleep(1);
  }
  return 0;
}