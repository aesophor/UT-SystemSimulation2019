#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

double DoubleRand() {
    return double(rand()) / (double(RAND_MAX) + 1.0);
}

int main() {
    srand(time(nullptr));
    vector<int> distribution(10); // 10 intervals

    cout << "Generating 100 doubles" << endl;
    for (int i = 0; i < 100; i++) {
        double num = DoubleRand();
        cout << num << " ";

        for (int i = 0; i < 10; i++) {
            double lowerbound = 0.1 * i;
            double upperbound = lowerbound + 0.1;

            if (num >= lowerbound && num < upperbound) {
                distribution.at(i)++;
                break;
            }
        }
    }

    double d_sum = 0;
    for (auto dist : distribution) {
        d_sum += pow(dist - 10, 2) / 10;
    }

    cout << endl << endl << "D Sum: " << d_sum << endl
        << "Chi-Square Test "
        << ((d_sum < 16.92) ? "passed" : "failed") << endl;
}
