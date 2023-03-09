/*
 * =====================================================================================
 *
 *       Filename:  walls_and_gates.cpp
 *
 *    Description:  286. Walls and Gates.
 *                  https://leetcode.com/problems/walls-and-gates/
 *
 *        Version:  1.0
 *        Created:  03/09/23 08:58:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

// Depth first search
class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    vector<vector<bool>> visited(rooms.size(),
                                 vector<bool>(rooms[0].size(), false));
    for (int i = 0; i < rooms.size(); i++) {
      for (int j = 0; j < rooms[i].size(); j++) {
        if (rooms[i][j] == 0) {
          dfsTraversal(rooms, visited, i, j, 0);
        }
      }
    }
  }

 private:
  void dfsTraversal(vector<vector<int>>& rooms, vector<vector<bool>>& visited,
                    int i, int j, int dis) {
    if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size() ||
        rooms[i][j] == -1) {
      return;
    }
    if (visited[i][j] || dis > rooms[i][j]) {
      return;
    }
    if (rooms[i][j] != 0) {
      rooms[i][j] = std::min(rooms[i][j], dis);
    }
    visited[i][j] = true;
    dfsTraversal(rooms, visited, i + 1, j, dis + 1);
    dfsTraversal(rooms, visited, i - 1, j, dis + 1);
    dfsTraversal(rooms, visited, i, j + 1, dis + 1);
    dfsTraversal(rooms, visited, i, j - 1, dis + 1);
    visited[i][j] = false;
  }
};

TEST(Solution, wallsAndGates) {
  vector<std::pair<vector<vector<int>>, vector<vector<int>>>> cases = {
      std::make_pair(
          vector<vector<int>>{
              vector<int>{2147483647, -1, 0, 2147483647},
              vector<int>{2147483647, 2147483647, 2147483647, -1},
              vector<int>{2147483647, -1, 2147483647, -1},
              vector<int>{0, -1, 2147483647, 2147483647}},
          vector<vector<int>>{
              vector<int>{3, -1, 0, 1}, vector<int>{2, 2, 1, -1},
              vector<int>{1, -1, 2, -1}, vector<int>{0, -1, 3, 4}}),
      std::make_pair(
          vector<vector<int>>{
              vector<int>{0, -1},
              vector<int>{2147483647, 2147483647},
          },
          vector<vector<int>>{
              vector<int>{0, -1},
              vector<int>{1, 2},
          }),
  };
  for (auto& c : cases) {
    Solution().wallsAndGates(c.first);
    EXPECT_THAT(c.first, testing::ElementsAreArray(c.second));
  }
}
