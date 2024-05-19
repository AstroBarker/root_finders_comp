/**
 * File    : funcs.hpp
 * Author  : Brandon Barker
 * Purpose : Functions to solve
 **/

#ifndef FUNCS_HPP_
#define FUNCS_HPP_

#include <math.h>

#include "abstractions.hpp"

namespace Functions {

Real f1( Real x ) { return x * exp( -x ); }
Real df1( Real x ) { return exp( -x ) - x * exp( -x ); }

// multiple roots, including 0, 1.876.., 2.988.., .....
Real f2( Real x ) { return x * exp( -x ) + sin( x ) * cos( x ); }

Real df2( Real x ) {
  return -exp( -x ) * ( x + exp( 2.0 * x ) * sin( x ) * sin( x ) - 1.0 ) +
         exp( x ) * cos( x ) * cos( x ) + exp( x ) * sin( x ) * cos( x );
}

Real g( Real x ) { return sin( x ) + atan( x ) - x; }

} // namespace Functions

#endif // FUNCS_HPP_
