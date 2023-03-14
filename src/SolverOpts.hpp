#ifndef _SOLVEROPTS_HPP_
#define _SOLVEROPTS_HPP_

/**
 * This file contains various solver options
 **/

#include "Abstractions.hpp"

namespace Opts {

constexpr unsigned int MAX_ITERS = 20;
constexpr Real FPTOL = 1.0e-11;
constexpr Real ZBARTOL = 1.0e-13;
constexpr Real ZBARTOLINV = 1.0e13;

} // namespace Opts

#endif // _SOLVEROPTS_HPP_
