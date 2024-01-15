#include <math.h>
#include <cstdio>

#include "Abstractions.hpp"
#include "Funcs.hpp"
#include "Solvers.hpp"
#include "Timer.hpp"

int main( int argc, char *argv[] ) {

  const Real x0 = - 0.25;

  Timer timer;

  timer.start();
  std::printf( "# Fixed Point \n" );
  Real result_fp = FixedPointSolve( Functions::f2, -2.0, 0.0, -0.25 );
  timer.stop();
  std::printf("# Fixed point runtime: %e ns \n\n", timer.elapsedNanoseconds());

  timer.start();
  std::printf( "# Newton ~\n" );
  Real result_n = Newton( Functions::f, Functions::df2, -2.0, 0.0, -0.25 );
  timer.stop();
  std::printf("# Newton runtime: %e ns \n\n", timer.elapsedNanoseconds());

  timer.start();
  std::printf( "# Anderson Accelerated Newton ~\n" );
  Real result_aan = AANewton( Functions::f2, Functions::df2, -2.0, 0.0, -0.25 );
  timer.stop();
  std::printf("# Anerson Accerated Newton runtime: %e ns \n\n", timer.elapsedNanoseconds());

  return 0;
}
