/**
 * File    : Solvers.hpp
 * Author  : Brandon Barker
 * Purpose : Implement various root finders
 **/

#include <algorithm>
#include <cstdio>

#include "Funcs.hpp"
#include "SolverOpts.hpp"

/* returns true if bracket contains a root (ya * yb < 0) */
bool check_bracked( Real ya, Real yb ) {
  return (ya * yb <= 0.0);
}

/**
 * Fixed point solver templated on type, function
 * Assumes input func target is of type f(x) = 0. Modified in body.
 **/
template <typename T, typename F>
T FixedPoint( F target, T a, T b, T x0 ) {

  // puts f(x) = 0 into fixed point form
  auto f = [&]( const Real x ) { return target( x ) + x; };

  unsigned int n = 0;
  T error        = 1.0;
  T ans;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    T x1  = f(x0);
    error = std::fabs( x1 - x0 );
    x0    = x1;
    n += 1;

    printf( " %d %e %e \n", n, x1, error );
    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
    }
    ans = x1;
  }

  return ans;
}

/**
 * Anderson accelerated fixed point solver templated on type, function
 * Assumes input func target is of type f(x) = 0. Modified in body.
 **/
template <typename T, typename F>
T FixedPointAA( F target, T a, T b, T x0 ) {

  // puts f(x) = 0 into fixed point form
  auto f = [&]( const Real x ) { return target( x ) + x; };

  // residual function, used in AA algorithm
  auto g = [&]( const Real x ) { return f( x ) - x; };

  unsigned int n = 0;
  T error        = 1.0;
  T xkm1, xk, xkp1;
  xk   = f( x0 ); // one fixed point step
  xkm1 = x0;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    /* Anderson acceleration step */
    T alpha = -g( xk ) / ( g( xkm1 ) - g( xk ) );

    T xkp1 = alpha * f( xkm1 ) + ( 1.0 - alpha ) * f( xk );
    error  = std::fabs( xk - xkp1 );

    xkm1 = xk;
    xk   = xkp1;

    n += 1;

    printf( " %d %e %e \n", n, xk, error );
    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
    }
  }

  return xk;
}

/**
 * Anderson accelerated fixed point solver templated on type, function, args...
 * Assumes target is of type f(x) = x
 * TODO: update style?
 **/
template <typename T, typename F, typename... Args>
T FixedPointAA( F target, T x0, Args... args ) {

  // puts f(x) = 0 into fixed point form
  auto f = [&]( const Real x, Args... args ) { return target( x, args... ) + x; };

  // residual function, used in AA algorithm
  auto g = [&]( const Real x ) { return f( x ) - x; };

  unsigned int n = 0;
  T error        = 1.0;
  T xkm1, xk, xkp1;
  xk   = target( x0, args... ); // one fixed point step
  xkm1 = x0;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    /* Anderson acceleration step */
    T alpha = -g( target, xk, args... ) / ( g( target, xkm1, args... ) - g( target, xk, args... ) );

    T xkp1 = alpha * target( xkm1, args... ) + ( 1.0 - alpha ) * target( xk, args... );
    error  = std::fabs( xk - xkp1 );

    xkm1 = xk;
    xk   = xkp1;

    n += 1;

    printf( " %d %e %e \n", n, xk, error );
    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
    }
  }

  return xk;
}

/* Newton iteration templated on type, function */
template <typename T, typename F>
T Newton( F target, F dTarget, T a, T b, T x0 ) {

  unsigned int n = 0;
  T h            = target( x0 ) / dTarget( x0 );
  T error        = 1.0;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    T xn  = x0;
    T h   = target( xn ) / dTarget( xn );
    x0    = xn - h;
    error = std::fabs( xn - x0 );
    n += 1;
    printf( " %d %e %e \n", n, xn, error );
    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
      printf( " %d %e %e \n", n, xn, error );
    }
  }
  return x0;
}

/* Anderson Accelerated Newton iteration templated on type, function */
template <typename T, typename F>
T AANewton( F target, F dTarget, T a, T b, T x0 ) {

  unsigned int n = 0;
  T h            = target( x0 ) / dTarget( x0 );
  T error        = 1.0;
  T xkm1, xk, xkp1;
  xk   = x0 - h;
  xkm1 = x0;
  T ans;
  while ( n <= Opts::MAX_ITERS && error >= Opts::FPTOL ) {
    T hp1 = target( xk ) / dTarget( xk );
    T h   = target( xkm1 ) / dTarget( xkm1 );
    /* Anderson acceleration step */
    T gamma = hp1 / ( hp1 - h );

    xkp1  = xk - hp1 - gamma * ( xk - xkm1 - hp1 + h );
    error = std::fabs( xk - xkp1 );

    xkm1 = xk;
    xk   = xkp1;

    n += 1;
    printf( " %d %e %e \n", n, xk, error );
    if ( n == Opts::MAX_ITERS ) {
      std::printf( " ! Not Converged ! \n" );
      printf( " %d %e %e \n", n, xk, error );
    }
    ans = xk;
  }
  return ans;
}
