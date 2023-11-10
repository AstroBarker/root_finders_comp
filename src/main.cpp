#include <math.h>
#include <cstdio>

#include "Abstractions.hpp"
#include "Funcs.hpp"
#include "Solvers.hpp"
#include "Timer.hpp"

int main( int argc, char *argv[] ) {

  const Real x0 = 1.0;
  std::printf( "# Fixed Point \n" );
  Real result_fp = FixedPointSolve( Functions::f, -2.0, 0.0, -0.25 );
  std::printf( "# Newton ~\n" );
  Real result_n = Newton( Functions::f, Functions::df, -2.0, 0.0, -0.25 );
  std::printf( "# Anderson Accelerated Newton ~\n" );
  Real result_aan = AANewton( Functions::f, Functions::df, -2.0, 0.0, -0.25 );

  return 0;
}
