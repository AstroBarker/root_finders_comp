/**
 * File    : Solve.hpp
 * Author  : Brandon Barker
 * Purpose : Implement Anderson-accelerated fixed point iteration
 * TODO: do the Anderson acceleration...
 **/

#include <cstdio>
#include <algorithm>

#include "SolverOpts.hpp"

/* templated residual function */
template <typename T, typename F>
T Residual( F g, T x0 ) {
  return g( x0 ) - x0;
}

/* Fixed point solver templated on type, function, and args for func */
template <typename T, typename F>
T FixedPointSolve( F target, T a, T b, T guess ) {

  unsigned int n = 0;
  T error        = 1.0;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    T x1  = target( x0 );
    error = std::abs( Residual( target, x0 ) );
    printf( " %d %f %f \n", n, x1, error );
    x0 = x1;
    n += 1;

    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
    }
  }

  return x0;
}
