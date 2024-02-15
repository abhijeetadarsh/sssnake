#include <iostream>
// #include <time.h>
#include <sys/time.h>

int main()
{
  timeval now;
  // timespec now;
  // clock_gettime(0, &now);
  // clock_getres()
  gettimeofday(&now, nullptr);
  std::cout << now.tv_sec << " " << now.tv_usec << "\n";
  return 0;
}