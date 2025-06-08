/*
 * =====================================================================================
 *
 *       Filename:  lexicographical_numbers.cpp
 *
 *    Description:  Lexicographical Numbers.
 *                  Given an integer n, return 1 - n in lexicographical order.
 *
 *        Version:  1.0
 *        Created:  07/02/18 07:06:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution1 {
 public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> nums;

    int k = 1;
    for (int i = 0; i < n; i++) {
      nums.push_back(k);
      if (k * 10 <= n) {
        k *= 10;
      } else {
        k += 1;
        if ((k % 10) == 0) {
          k /= 10;
        } else if (k > n) {
          k /= 10;
          k += 1;
        }
        while ((k % 10) == 0) {
          k /= 10;
        }
      }
    }

    return nums;
  }
};

// Depth first search
class Solution2 {
 public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> nums;
    for (int i = 1; i <= 9; i++) {
      genLexicalOrder(n, i, nums);
    }
    return nums;
  }

 private:
  void genLexicalOrder(int n, int k, std::vector<int>& nums) {
    if (k > n) {
      return;
    }
    nums.push_back(k);
    for (int i = 0; i <= 9; i++) {
      int next = k * 10 + i;
      if (next > n) {
        break;
      }
      genLexicalOrder(n, next, nums);
    }
  }
};

TEST(Solution, lexicalOrder) {
  std::vector<std::pair<int, std::vector<int>>> cases = {
      {13, {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9}},
      {2, {1, 2}},
  };
  for (auto& [n, nums] : cases) {
    EXPECT_THAT(Solution1().lexicalOrder(n), testing::ElementsAreArray(nums));
    EXPECT_THAT(Solution2().lexicalOrder(n), testing::ElementsAreArray(nums));
  }
}
