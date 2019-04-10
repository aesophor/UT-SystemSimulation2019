#include "random_util.h"

#include <iostream>
#include <cmath>

using std::pow;
using std::vector;
using std::cout;
using std::endl;

namespace random_util {

vector<int> LinearCongruential(int seed, int a, int c, int m, int count) {
  // The congruential method uses the following recursive relationship
  // to generate random numbers: Xi+1 = (a * Xi + c) % m
  vector<int> result(count);
  result[0] = seed; // X0 = 1

  for (int i = 1; i < count; i++) {
    result[i] = (a * result[i - 1] + c) % m;
  }
  return result;
}

vector<int> QuadraticCongruential(int seed1, int seed2, int a1, int a2, int c, int m, int count) {
  // Xi+1 = (a1 * (Xi^2) + a2 * Xi-1 + c) % m
  vector<int> result(count);
  result[0] = seed1; // X0 = 1
  result[1] = seed2; // X1 = 1

  for (int i = 2; i < count; i++) {
    result[i] = (int)(a1 * pow(result[i - 1], 2) + a2 * result[i - 2] + c) % m;
  }
  return result;
}

int Tausworthe(bool seed, const vector<int>& a) {
  static const int kIntBitCount = 8;

  vector<bool> bits(kIntBitCount, false);
  bits[kIntBitCount - 1] = seed;

  for (int i = kIntBitCount - 1; i >= 0; i--) {
    for (auto bit : bits) {
      cout << bit << " ";
    }
    cout << endl;

    int current = 0;
    int a_idx = 0;
    for (int j = i + 1; j < kIntBitCount; j++, a_idx++) {
      current += a[a_idx] * bits[j];
    }
    bits[i] = current % 2;
  }

  int result = 0;
  for (auto bit : bits) {
    result <<= 1;
    result += bit;
  }
  return result;
}

} // namespace random_util
