/*
 * =====================================================================================
 *
 *       Filename:  count_bits.cpp
 *
 *    Description:  339. Counting Bits https://leetcode.com/problems/counting-bits/
 *
 *        Version:  1.0
 *        Created:  03/01/2022 11:46:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>

// Dynamic programming, O(n)
class Solution {
 public:
  std::vector<int> countBits(int n) {
    // f(0) = 0
    // f(1) = 1
    // f(8) = 1
    // f(9) = f(8) + f(1)
    // f(10) = f(8) + f(2)
    // f(11) = f(8) + f(3)
    if (n < 1) {
      return {0};
    }

    std::vector<int> bits(n + 1, 0);
    bits[1] = 1;
    int pre = 1;
    for (int i = 1; i <= 31 && pre < n; i++) {
      int end = std::pow(2, i);
      if (end <= n) {
        bits[end] = 1;
      } else {
        end = n + 1;
      }
      for (int j = pre + 1; j < end; j++) {
        bits[j] = bits[pre] + bits[j - pre];
      }
      pre = end;
    }
    return bits;
  }
};

int main(int argc, char* argv[]) {
  int num = 2;
  if (argc > 1) {
    num = std::atoi(argv[1]);
  }
  std::vector<int> bits = Solution().countBits(num);
  for (int i = 0; i < bits.size(); i++) {
    printf("%d%s", bits[i], (i == bits.size() - 1 ? "\n" : " "));
  }
  return 0;
}
