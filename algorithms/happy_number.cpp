/*
 * =====================================================================================
 *
 *       Filename:  happy_number.cpp
 *
 *    Description:  202. Happy Number https://leetcode.com/problems/happy-number/
 *
 *        Version:  1.0
 *        Created:  02/22/2022 15:29:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <unordered_set>

class Solution {
 public:
  bool isHappy(int n) {
    auto replace = [](int n) -> int {
      int sum = 0;
      while (n != 0) {
        sum += std::pow(static_cast<double>(n % 10), 2.0);
        n /= 10;
      }
      return sum;
    };

    std::unordered_set<int> nums;
    while (true) {
      nums.insert(n);
      n = replace(n);
      if (nums.count(n) > 0) {
        break;
      }
    }
    return (n == 1);
  }
};

int main(int argc, char* argv[]) {
  int n = 19;
  if (argc > 1) {
    n = std::atoi(argv[1]);
  }
  printf("n = %d\n", n);
  printf("%s\n", (Solution().isHappy(n) ? "true" : "false"));
  return 0;
}
