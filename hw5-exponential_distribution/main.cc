#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

double DoubleRand() {
  return double(rand()) / (double(RAND_MAX) + 1.0);
}

int CountLessEqualThan(const vector<double>& nums, double target) {
  int count = 0;
  for (auto num : nums) {
    if (num <= target) {
      count++;
    }
  }
  return count;
}

int main() {
  srand(time(nullptr));

  const double kLambda = 1.0;
  const double kExp = 2.71828183;
  const int kDataCount = 200;

  vector<double> U(kDataCount, 0);
  for (auto& num : U) {
    num = DoubleRand();
  }
  U.at(0) = 0.874791;

  vector<double> X(kDataCount, 0);
  for (int i = 0; i < kDataCount; i++) {
    X.at(i) = ((double) -1) / kLambda * std::log(1 - U.at(i));
  }

  vector<double> x(kDataCount, 0);
  x.at(0) = 0.05;
  for (int i = 1; i < kDataCount; i++) {
    x.at(i) = x.at(i - 1) + 0.05;
  }

  vector<double> cdf(kDataCount, 0);
  for (int i = 0; i < kDataCount; i++) {
    cdf.at(i) = 1 - std::pow(kExp, -kLambda * x.at(i));
  }

  vector<double> res(kDataCount, 0);
  for (int i = 0; i < kDataCount; i++) {
    res.at(i) = CountLessEqualThan(X, x.at(i));
  }


  cout << "id\t  U  \t\t X  \t\t x  \t P(X<=x)  \t count" << endl;
  for (int i = 0; i < kDataCount; i++) {
    cout << i << "\t  "
      << U.at(i) << "\t  "
      << X.at(i) << "\t  "
      << x.at(i) << "\t  "
      << cdf.at(i) << "\t  "
      << res.at(i) << endl;
  }
}
