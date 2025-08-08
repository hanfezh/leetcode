/*
 * =====================================================================================
 *
 *       Filename:  max_collected_fruits.cpp
 *
 *    Description:  3363. Find the Maximum Number of Fruits Collected
 *                  https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/
 *
 *        Version:  1.0
 *        Created:  08/08/2025 10:57:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <initializer_list>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int maxCollectedFruits(std::vector<std::vector<int>>& fruits) {
    const int n = fruits.size();
    int child1 = 0;
    for (int i = 0; i < n; i++) {
      child1 += fruits[i][i];
    }

    std::vector<std::vector<int>> child2(n, std::vector<int>(n, -1));
    std::initializer_list<std::pair<int, int>> moves2{{1, -1}, {1, 0}, {1, 1}};
    child2[0][n - 1] = fruits[0][n - 1];
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (child2[i][j] == -1) {
          continue;
        }
        for (auto [first, second] : moves2) {
          const int x = i + first;
          const int y = j + second;
          if (x < 0 || x >= n || y < 0 || y >= n) {
            continue;
          }
          if (x >= y) {
            continue;
          }
          child2[x][y] = std::max(child2[x][y], child2[i][j] + fruits[x][y]);
        }
      }
    }

    std::vector<std::vector<int>> child3(n, std::vector<int>(n, -1));
    std::initializer_list<std::pair<int, int>> moves3{{-1, 1}, {0, 1}, {1, 1}};
    child3[n - 1][0] = fruits[n - 1][0];
    for (int j = 0; j < n; j++) {
      for (int i = j + 1; i < n; i++) {
        if (child3[i][j] == -1) {
          continue;
        }
        for (auto [first, second] : moves3) {
          const int x = i + first;
          const int y = j + second;
          if (x < 0 || x >= n || y < 0 || y >= n) {
            continue;
          }
          if (x <= y) {
            continue;
          }
          child3[x][y] = std::max(child3[x][y], child3[i][j] + fruits[x][y]);
        }
      }
    }

    return (child1 + child2[n - 2][n - 1] + child3[n - 1][n - 2]);
  }
};

TEST(Solution, maxCollectedFruits) {
  std::vector<std::pair<std::vector<std::vector<int>>, int>> cases = {
      {{{1, 2, 3, 4}, {5, 6, 8, 7}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 100},
      {{{1, 1}, {1, 1}}, 4},
  };
  for (auto& [fruits, result] : cases) {
    EXPECT_EQ(Solution().maxCollectedFruits(fruits), result);
  }
}
