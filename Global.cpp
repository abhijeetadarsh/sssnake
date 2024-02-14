#include <utility>

#ifndef GLOBAL
#define GLOBAL

template<typename _T>
constexpr bool is_one_of(_T&& a) { return false; }

template<typename _T, typename _U0, typename ... _U>
constexpr bool is_one_of(_T&& a, _U0&& u0, _U&& ... u) { return (a == u0) || is_one_of(a, std::forward<_U>(u)...); }

#endif