#include <iostream>
#include <vector>
#include <numeric>
#include <ctime>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

inline double DoubleRand() {
  return double(rand()) / (double(RAND_MAX) + 1.0);
}

int main() {
  srand(time(nullptr));
  vector<int> distribution(10, 0); // 10 intervals between 0.0 ~ 1.0

  // Generate 100 random numbers in [0,1]
  cout << "[*] Generating 100 random numbers:" << endl;
  for (int i = 0; i < 100; i++) {
    double num = DoubleRand();
    cout << num << " ";

    // Update distribution according to its value
    for (int j = 0; j < 10; j++) {
      double lo = 0.1 * j;
      double hi = lo + 0.1;
      if (lo <= num && num < hi) {
        distribution[j]++;
        break;
      }
    }
  }
  cout << endl << endl;

  // Chi-square test
  vector<double> chi_square(10);
  const int e = 10; // expected frequency for numbers in each interval
  cout << "[*] Chi-square test:" << endl;
  for (int i = 0; i < 10; i++) {
    chi_square[i] = std::pow((distribution[i] - e), 2) / e;
    cout << chi_square[i] << " ";
  }

  // Sum up chi_square
  double sum = std::accumulate(chi_square.begin(), chi_square.end(), 0.0);
  cout << "result: " << sum << endl;
  cout << ((sum < 16.92) ? "Passed" : "Failed") << endl;

  return EXIT_SUCCESS;
}
