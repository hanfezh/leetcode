/*
 * =====================================================================================
 *
 *       Filename:  rotated_digits.cpp
 *
 *    Description:  788. Rotated Digits.
 *                  https://leetcode.com/problems/rotated-digits/
 *
 *        Version:  1.0
 *        Created:  02/19/19 12:29:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

// Brute force
class Solution1 {
 public:
  int rotatedDigits(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
      if (isValidNumber(i)) {
        count++;
      }
    }
    return count;
  }

 private:
  bool isValidNumber(int num) {
    bool changed = false;
    while (num > 0) {
      const int unit = num % 10;
      if (unit == 2 || unit == 5 || unit == 6 || unit == 9) {
        // Value changed
        changed = true;
      } else if (unit == 3 || unit == 4 || unit == 7) {
        // Invalid number
        return false;
      } else {
        ;  // 0, 1, 8, value not changed
      }
      num = num / 10;
    }
    return changed;
  }
};

// Dynamic programming
class Solution2 {
 public:
  int rotatedDigits(int num) {
    int count = 0;
    vector<int> dp(num + 1);
    for (int i = 0; i < (num + 1); i++) {
      if (i < 10) {
        if (i == 0 || i == 1 || i == 8) {
          // Value not changed
          dp[i] = 0;
        } else if (i == 2 || i == 5 || i == 6 || i == 9) {
          // Value changed
          dp[i] = 1;
          count++;
        } else {
          // Invalid number
          dp[i] = -1;
        }
      } else {
        const int a = i / 10;
        const int b = i % 10;
        if (dp[a] >= 0 && dp[b] >= 0) {
          if (dp[a] == 0 && dp[b] == 0) {
            dp[i] = 0;
          } else {
            dp[i] = 1;
            count++;
          }
        } else {
          dp[i] = -1;
        }
      }
    }
    return count;
  }
};

TEST(Solution, rotatedDigits) {
  vector<std::pair<int, int>> cases = {
      std::make_pair(1, 0),
      std::make_pair(2, 1),
      std::make_pair(10, 4),
      std::make_pair(857, 247),
  };
  for (const auto& c : cases) {
    EXPECT_EQ(Solution1().rotatedDigits(c.first), c.second);
    EXPECT_EQ(Solution2().rotatedDigits(c.first), c.second);
  }
}
