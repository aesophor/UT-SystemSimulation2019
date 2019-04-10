#include "random_util.h"

using std::vector;

namespace random_util {

vector<int> CongruentialMethod(int a, int c, int m, int count) {
  // The congruential method uses the following recursive relationship
  // to generate random numbers: Xi+1 = (a * (Xi) + c) % m
  vector<int> result(count);
  result[0] = 1; // X0 = 1

  for (int i = 1; i < count; i++) {
    result[i] = (a * result[i - 1] + c) % m;
  }
  return result;
}

} // namespace random_util
