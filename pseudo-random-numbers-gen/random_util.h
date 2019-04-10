#ifndef RANDOM_UTIL_H_
#define RANDOM_UTIL_H_

#include <vector>

namespace random_util {

std::vector<int> CongruentialMethod(int a, int c, int m, int count);

} // namespace random_util

#endif // RANDOM_UTIL_H_
