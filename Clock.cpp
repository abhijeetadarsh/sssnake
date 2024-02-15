#ifndef CLOCK
#define CLOCK

#include <sys/time.h>
class Clock
{
  timeval _m_last_refresh_time;
  int _m_threshold__microseconds;
public:
  Clock(int threshold__microseconds) : _m_threshold__microseconds{ threshold__microseconds } {
    gettimeofday(&_m_last_refresh_time, nullptr);
  }

  bool tick()
  {
    timeval now; gettimeofday(&now, nullptr);
    int diff = now.tv_usec - _m_last_refresh_time.tv_usec + 1000000 * (now.tv_sec - _m_last_refresh_time.tv_sec);
    
    if(diff >= _m_threshold__microseconds)
    {
      _m_last_refresh_time = now;
      return true;
    }

    return false;
  }
};

#endif