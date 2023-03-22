/**
 * File    : Solvers.hpp
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

/* Fixed point solver templated on type, function */
template <typename T, typename F>
T FixedPointSolve( F target, T a, T b, T x0 ) {

  unsigned int n = 0;
  T error        = 1.0;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    T x1  = target( x0 );
    x0 = x1;
    error = std::abs( Residual( target, x1 ) );
    n += 1;

    printf( " %d %f %f \n", n, x1, error );
    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
    }
  }

  return x0;
}

/* Newton iteration templated on typem function */
template <typename T, typename F>
T Newton( F target, F dTarget, T a, T b, T x0 ) { 

  unsigned int n = 0;
  T h = target( x0 ) / dTarget( x0 );
  T error = 1.0;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    T xn = x0;
    T h = target( xn ) / dTarget( xn );
    x0 = xn - h;
    error = std::abs( xn - x0 );
    n += 1;
    printf( " %d %f %e \n", n, xn, error );
    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
    printf( " %d %f %e \n", n, xn, error );
    }
  }
  return x0;
}

/* Newton iteration templated on typem function */
template <typename T, typename F>
T AANewton( F target, F dTarget, T a, T b, T x0 ) { 

  unsigned int n = 0;
  T h = target( x0 ) / dTarget( x0 );
  T error = 1.0;
  T xkm1, xk, xkp1;
  xk = x0;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    /* Anderson acceleration step */
    T gkm1 = ( n == 0 ) ? 0.0 : target( xkm1 );
    T gk = target( xk );
    T gamma = gk / ( gk + gkm1 );

    T h = target( xk ) / dTarget( xk );
    x0 = xk - h;
    error = std::abs( xk - x0 );
    n += 1;
    printf( " %d %f %e \n", n, xk, error );
    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
    printf( " %d %f %e \n", n, xk, error );
    }
  }
  return x0;
}
