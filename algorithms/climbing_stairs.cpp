/*
 * =====================================================================================
 *
 *       Filename:  climbing_stairs.cpp
 *
 *    Description:  70. Climbing Stairs. You are climbing a stair case. It takes n steps
 *                  to reach to the top. Each time you can either climb 1 or 2 steps. In
 *                  how many distinct ways can you climb to the top?
 *
 *        Version:  1.0
 *        Created:  02/18/19 02:18:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <unordered_map>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Iteractive
class Solution1 {
 public:
  int climbStairs(int n) {
    if (n < 1) {
      return 0;
    }

    std::vector<int> ways(n > 2 ? n : 2);
    ways[0] = 1;
    ways[1] = 2;

    for (int i = 2; i < n; i++) {
      ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n - 1];
  }
};

// Recursive
class Solution2 {
 public:
  int climbStairs(int n) {
    std::unordered_map<int, int> cache;
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    return climbStairs(n, cache);
  }

 private:
  int climbStairs(int n, std::unordered_map<int, int>& cache) {
    auto iter = cache.find(n);
    if (iter != cache.end()) {
      return iter->second;
    }

    int val = climbStairs(n - 1, cache) + climbStairs(n - 2, cache);
    cache[n] = val;
    return val;
  }
};

// Time complexity: O(n)
// Space complexity: O(1)
class Solution3 {
 public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }

    int a = 1;
    int b = 2;
    int c = 0;
    for (int i = 2; i < n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};

TEST(Solution, climbStairs) {
  std::vector<std::pair<int, int>> cases = {
      std::make_pair(1, 1),
      std::make_pair(2, 2),
      std::make_pair(3, 3),
      std::make_pair(5, 8),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().climbStairs(c.first), c.second);
    EXPECT_EQ(Solution2().climbStairs(c.first), c.second);
    EXPECT_EQ(Solution3().climbStairs(c.first), c.second);
  }
}
