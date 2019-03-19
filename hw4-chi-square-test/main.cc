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

    for (int i = 0; i < 100; i++) {
        double num = DoubleRand();
        cout << num << " ";

        if (num >= 0 && num < 0.1) {
            distribution.at(0)++;
        } else if (num >= 0.1 && num < 0.2) {
            distribution.at(1)++;
        } else if (num >= 0.2 && num < 0.3) {
            distribution.at(2)++;
        } else if (num >= 0.3 && num < 0.4) {
            distribution.at(3)++;
        } else if (num >= 0.4 && num < 0.5) {
            distribution.at(4)++;
        } else if (num >= 0.5 && num < 0.6) {
            distribution.at(5)++;
        } else if (num >= 0.6 && num < 0.7) {
            distribution.at(6)++;
        } else if (num >= 0.7 && num < 0.8) {
            distribution.at(7)++;
        } else if (num >= 0.8 && num < 0.9) {
            distribution.at(8)++;
        } else if (num >= 0.9 && num < 1.0) {
            distribution.at(9)++;
        }
    }

    double d_sum = 0;
    for (auto dist : distribution) {
        d_sum += pow(dist - 10, 2) / 10;
    }

    cout << endl << "D Sum: " << d_sum << endl;
    if (d_sum < 16.92) {
        cout << "Chi-square passed" << endl;
    } else {
        cout << "Chi-square failed" << endl;
    }
}
