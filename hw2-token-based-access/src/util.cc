#include "util.h"

using std::vector;

namespace util {

int min(const vector<int>& numbers) {
    int min = numbers[0];
    for (auto num : numbers) {
        if (num < min) {
            min = num;
        }
    }
    return min;
}

} // namespace util
