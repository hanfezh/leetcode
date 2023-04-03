// 509. Fibonacci Number: https://leetcode.com/problems/fibonacci-number
// Author: xianfeng.zhu@gmail.com

#include <initializer_list>
#include <unordered_map>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::initializer_list;
using std::pair;
using std::vector;

// Recursive
class Solution1 {
 public:
  int fib(int n) {
    std::unordered_map<int, int> cache;
    cache[0] = 0;
    cache[1] = 1;
    return fib(n, cache);
  }

 private:
  int fib(int n, std::unordered_map<int, int>& cache) {
    auto iter = cache.find(n);
    if (iter != cache.end()) {
      return iter->second;
    }

    int val = fib(n - 2, cache) + fib(n - 1, cache);
    cache[n] = val;
    return val;
  }
};

// Dynamic programming
class Solution2 {
 public:
  int fib(int n) {
    if (n < 1) {
      return 0;
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

// Dynamic programming with less space
class Solution3 {
 public:
  int fib(int n) {
    int a = 0, b = 1, c = 0;
    for (int i = 2; i < n + 1; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return (n > 1 ? c : n);
  }
};

TEST(Solution, fib) {
  initializer_list<pair<int, int>> cases = {
      std::make_pair(2, 1),
      std::make_pair(3, 2),
      std::make_pair(4, 3),
  };
  for (auto c : cases) {
    EXPECT_EQ(Solution1().fib(c.first), c.second);
    EXPECT_EQ(Solution2().fib(c.first), c.second);
    EXPECT_EQ(Solution3().fib(c.first), c.second);
  }
}
