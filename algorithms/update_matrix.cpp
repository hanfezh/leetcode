/*
 * =====================================================================================
 *
 *       Filename:  update_matrix.cpp
 *
 *    Description:  542. 01 Matrix. https://leetcode.com/problems/01-matrix/
 *
 *        Version:  1.0
 *        Created:  04/03/23 16:23:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <array>
#include <climits>
#include <queue>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;

// Breadth first search
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    const int rows = mat.size();
    const int cols = mat[0].size();
    vector<vector<int>> dis(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> visited;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (mat[i][j] == 0) {
          dis[i][j] = 0;
          visited.push({i, j});
        }
      }
    }

    array<pair<int, int>, 4> dir = {make_pair(-1, 0), {1, 0}, {0, -1}, {0, 1}};
    while (!visited.empty()) {
      auto p = visited.front();
      visited.pop();
      for (auto& d : dir) {
        const int i = p.first + d.first;
        const int j = p.second + d.second;
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
          continue;
        }
        if (dis[i][j] > dis[p.first][p.second] + 1) {
          dis[i][j] = dis[p.first][p.second] + 1;
          visited.push({i, j});
        }
      }
    }
    return dis;
  }
};

TEST(Solution, updateMatrix) {
  vector<pair<vector<vector<int>>, vector<vector<int>>>> cases = {
      std::make_pair(vector<vector<int>>{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
                     vector<vector<int>>{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}),
      std::make_pair(vector<vector<int>>{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}},
                     vector<vector<int>>{{0, 0, 0}, {0, 1, 0}, {1, 2, 1}}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().updateMatrix(c.first), testing::ElementsAreArray(c.second));
  }
}
