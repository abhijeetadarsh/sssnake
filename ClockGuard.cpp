#ifndef CLOCK
#define CLOCK

#include <sys/time.h>
#include <ncurses.h>
#include <cassert>

class ClockGuard
{
  timeval _m_last_refresh_time;
  int _m_threshold__microseconds;
public:
  ClockGuard(int threshold__microseconds) : _m_threshold__microseconds{ threshold__microseconds } {
    assert(threshold__microseconds < 1000000000);
    gettimeofday(&_m_last_refresh_time, nullptr);
  }

  bool tick()
  {
    return true;
    timeval now; gettimeofday(&now, nullptr);
    int duration__microseconds = now.tv_usec - _m_last_refresh_time.tv_usec + 1000000 * (now.tv_sec - _m_last_refresh_time.tv_sec);
    
    if(duration__microseconds >= _m_threshold__microseconds)
    {
      _m_last_refresh_time = now;
      return true;
    }

    return false;
  }
};

#endif