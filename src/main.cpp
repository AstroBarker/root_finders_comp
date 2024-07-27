#include <math.h>
#include <cstdio>

#include "abstractions.hpp"
#include "funcs.hpp"
#include "solvers.hpp"
#include "timer.hpp"

int main( int argc, char *argv[] ) {

  const Real x0 = -0.25;

  Timer timer;

  timer.start( );
  std::printf( "# Fixed Point \n" );
  Real result_fp = FixedPoint( Functions::f2, -2.0, 0.0, +0.001 );
  timer.stop( );
  std::printf( "# Fixed point runtime: %e ns \n\n",
               timer.elapsedNanoseconds( ) );

  timer.start( );
  std::printf( "# Anderson Accelerated Fixed Point \n" );
  Real result_fpaa = FixedPointAA( Functions::f2, -2.0, 0.0, -0.5 );
  timer.stop( );
  std::printf( "# Fixed point runtime: %e ns \n\n",
               timer.elapsedNanoseconds( ) );

  timer.start( );
  std::printf( "# Newton ~\n" );
  Real result_n = Newton( Functions::f2, Functions::df2, -2.0, 0.0, -0.5 );
  timer.stop( );
  std::printf( "# Newton runtime: %e ns \n\n", timer.elapsedNanoseconds( ) );

  timer.start( );
  std::printf( "# Anderson Accelerated Newton ~\n" );
  Real result_aan = AANewton( Functions::f2, Functions::df2, -2.0, 0.0, -0.5 );
  timer.stop( );
  std::printf( "# Anerson Accerated Newton runtime: %e ns \n\n",
               timer.elapsedNanoseconds( ) );

  return 0;
}
