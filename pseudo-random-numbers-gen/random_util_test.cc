#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "random_util.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

string Vec2String(const vector<int>& nums) {
  string result;
  for (size_t i = 0; i < nums.size(); i++) {
    result += std::to_string(nums[i]);
    result += (i == nums.size() - 1) ? "" : " ";
  }
  return result;
}

int main() {
  string result;

  // Linear Congruential Generator
  result = Vec2String(random_util::LinearCongruential(1, 2, 1, 10, 8)); // a, c, m, count
  assert(result == "1 3 7 5 1 3 7 5");
  cout << result << endl;

  result = Vec2String(random_util::LinearCongruential(1, 1, 7, 10, 8)); // a, c, m, count
  assert(result == "1 8 5 2 9 6 3 0");
  cout << result << endl;


  // Quadratic Congruential Generator
  result = Vec2String(random_util::QuadraticCongruential(1, 1, 2, 5, 7, 10, 10)); // a2, a2, c, m, count
  cout << result << endl;


  cout << "All tests has passed" << endl;
  return EXIT_SUCCESS;
}
