/**
 * File    : funcs.hpp
 * Author  : Brandon Barker
 * Purpose : Functions to solve
 **/

#ifndef _FUNCS_HPP_
#define _FUNCS_HPP_

#include <math.h>

#include "Abstractions.hpp"

namespace Functions {

Real f( Real x ) {
  // return x*x + 2.0*x - 1.0;
  return x * exp( -x );
}
Real df( Real x ) {
  // return 2.0*x + 2.0;
  return exp( -x ) - x * exp( -x );
}

// multiple roots, including 0, 1.6.., 3.13.., .....
Real f2( Real x ) { return x * exp( -x ) + sin( x ) * cos( x ); }

Real df2( Real x ) {
  return -exp( -x ) * ( x + exp( 2.0 * x ) * sin( x ) * sin( x ) - 1.0 ) +
         exp( x ) * cos( x ) * cos( x ) + exp( x ) * sin( x ) * cos( x );
}

Real g( Real x ) { return ( 1.0 + std::cos( x ) ) / 3.0; }

} // namespace Functions

#endif // _FUNCS_HPP_
