#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

double DoubleRand() {
  return double(rand()) / (double(RAND_MAX) + 1.0);
}

int CountLessEqualThan(const vector<int>& nums, int target) {
  int count = 0;
  for (auto n : nums) {
    if (n <= target) {
      count++;
    }
  }
  return count;
}

int main() {
  srand(time(nullptr));

  const int kTotal = 1000;
  const double kLambda = 4;
  const double kExp = 2.71828183;

  int n = 0;
  double p = 1;
  vector<int> nums;

  while (nums.size() < kTotal) {
    p *= DoubleRand();

    // If p < e^-lambda, accept N=n,
    // otherwise, reject the current n, n++.
    if (p < std::pow(kExp, -kLambda)) {
      cout << n << " ";
      nums.push_back(n);
      n = 0;
      p = 1;
    } else {
      n++;
    }
  }
  cout << endl;


  // Calulate poisson distribution
  cout << endl << "N\tP(N<n)" << endl;
  for (int i = 0; i < 100; i++) {
    int count = CountLessEqualThan(nums, i);
    double freq = (double) count / kTotal;
    cout << i << "\t" << freq << endl;
  }
}
