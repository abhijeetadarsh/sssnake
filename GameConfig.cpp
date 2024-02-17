#ifndef GAME_CONFIG
#define GAME_CONFIG

#include "ClockGuard.cpp"

class GameConfig
{
  bool _m_paused;

public:
  ClockGuard _m_clock;
  GameConfig() : _m_clock{ 166667 }, _m_paused{ false } {}

  void toggle_play_pause() { _m_paused = (_m_paused ? false : true); }
  bool is_paused() { return _m_paused; }

};

#endif