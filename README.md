# root_finders_comp
comparison of some root finders in C++

Purpose is to compare some root finders, in C++, on non-linear problems.

Standard Newton seems to outperform Anderson accelerated Newton in my tests (although literature shows there are cases where it wins, e.g.,  [Polllock and Schwartz 2019](https://arxiv.org/abs/1911.05238))
Implemented Anderson accelerated fixed point iteration shines.

## Root finders implemented
 - Fixed Point
 - Fixed Point (Anderson accelerated)
 - Newton
 - Newton (Anderson accelerated)

## Root Finders To Implement
 - Bisection
 - Regula Falsi
