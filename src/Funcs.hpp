/**
 * File    : funcs.hpp
 * Author  : Brandon Barker
 * Purpose : Functions to solve
 **/

#ifndef _FUNCS_HPP_
#define _FUNCS_HPP_

#include <math.h>

template < typename T >
T f( T x ) {
  return std::cos( x ) - 22.0 * x + 1.0;
}

template < typename T >
T g( T x ) {
  return ( - x + 1.0 + std::cos( x ) ) / 3.0;
}

#endif // _FUNCS_HPP_
