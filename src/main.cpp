#include <math.h>
#include <cstdio>

#include "Abstractions.hpp"
#include "Funcs.hpp"
#include "Solve.hpp"
#include "Timer.hpp"

int main( int argc, char *argv[] ) {

  const Real x0 = 1.0;
  Real result = FixedPointSolve( Functions::f, -2.0, 0.0, 0.8 );

  return 0;
}
