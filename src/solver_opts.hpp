#ifndef SOLVER_OPTS_HPP_
#define SOLVER_OPTS_HPP_

/**
 * This file contains various solver options
 **/

#include "abstractions.hpp"

namespace Opts {

constexpr unsigned int MAX_ITERS = 50;
constexpr Real FPTOL             = 1.0e-11;
constexpr Real ZBARTOL           = 1.0e-13;
constexpr Real ZBARTOLINV        = 1.0e13;

} // namespace Opts

#endif // SOLVER_OPTS_HPP_
