#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Generate pseudo random number U~[0,1]
inline double DoubleRand() {
  return double(rand()) / (double(RAND_MAX) + 1.0);
}

// Sample from a exponential distribution
double ExpRand(double lambda) {
  return ((double) -1) / lambda * log(1 - DoubleRand());
}


int main() {
  srand(time(nullptr));

  const int kCount = 100000;
  const double kAtLambda = 0.2;
  const double kStLambda = 0.25;
  vector<double> WT(kCount, 0);
  vector<double> ST(kCount, 0);
  vector<double> TW(kCount, 0);
  vector<double> AT(kCount, 0);
  
  for (int i = 1; i < kCount; i++) {
    // Generate AT
    AT[i] = ExpRand(kAtLambda);
    ST[i] = ExpRand(kStLambda);

    // Determine WTi+1
    if (AT[i] <= TW[i - 1]) {
      WT[i] = TW[i - 1] - AT[i];
    } else {
      WT[i] = 0;
    }

    TW[i] = WT[i] + ST[i];
  }

  double avg_wt = 0;
  for (auto t : WT) {
    avg_wt += t;
  }
  avg_wt = avg_wt / kCount;
  cout << "Avg waiting time: " << avg_wt << endl;
}
