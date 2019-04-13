#ifndef RANDOM_UTIL_H_
#define RANDOM_UTIL_H_

#include <vector>

namespace random_util {

int Rand(int lo, int hi);
std::vector<int> LinearCongruential(int seed, int a, int c, int m, int count);
std::vector<int> QuadraticCongruential(int seed1, int seed2, int a1, int a2, int c, int m, int count);

} // namespace random_util

#endif // RANDOM_UTIL_H_
