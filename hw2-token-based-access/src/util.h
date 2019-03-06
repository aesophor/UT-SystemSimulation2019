// Copyright 2019 Marco Wang <m.aesophor@gmail.com>

#ifndef UTIL_H_
#define UTIL_H_

#include <vector>

namespace util {

int min(const std::vector<int>& numbers) {
    int min = numbers[0];
    for (auto num : numbers) {
        if (num < min) {
            min = num;
        }
    }
    return min;
}

} // namespace util

#endif
