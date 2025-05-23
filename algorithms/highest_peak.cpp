/*
 * =====================================================================================
 *
 *       Filename:  highest_peak.cpp
 *
 *    Description:  1765. Map of Highest Peak
 *                  https://leetcode.com/problems/map-of-highest-peak/
 *
 *        Version:  1.0
 *        Created:  05/23/2025 14:38:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <array>
#include <queue>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Breadth first search
class Solution {
 public:
  std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& is_water) {
    const int rows = is_water.size();
    const int columns = is_water[0].size();
    const std::array<std::pair<int, int>, 4> moves{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
    std::vector<std::vector<int>> cell_heights(rows, std::vector<int>(columns, -1));
    std::queue<std::pair<int, int>> cell_queue;

    auto is_valid_cell = [&](const std::pair<int, int> cell) -> bool {
      return cell.first >= 0 && cell.first < rows && cell.second >= 0 && cell.second < columns;
    };

    // Add all water cells to the queue
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (is_water[i][j] == 1) {
          cell_queue.push({i, j});
          cell_heights[i][j] = 0;
        }
      }
    }

    int next_layer_height = 1;
    while (!cell_queue.empty()) {
      int layer_size = cell_queue.size();
      for (int i = 0; i < layer_size; i++) {
        std::pair<int, int> cell = cell_queue.front();
        cell_queue.pop();

        for (int i = 0; i < moves.size(); i++) {
          std::pair<int, int> neighbour{cell.first + moves[i].first, cell.second + moves[i].second};
          if (is_valid_cell(neighbour) && cell_heights[neighbour.first][neighbour.second] == -1) {
            cell_queue.push(neighbour);
            cell_heights[neighbour.first][neighbour.second] = next_layer_height;
          }
        }
      }
      next_layer_height++;
    }

    return cell_heights;
  }
};

TEST(Solution, highestPeak) {
  std::vector<std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>> cases = {
      std::make_pair(std::vector<std::vector<int>>{{0, 1}, {0, 0}},
                     std::vector<std::vector<int>>{{1, 0}, {2, 1}}),
      std::make_pair(std::vector<std::vector<int>>{{0, 0, 1}, {1, 0, 0}, {0, 0, 0}},
                     std::vector<std::vector<int>>{{1, 1, 0}, {0, 1, 1}, {1, 2, 2}})};
  for (auto& [is_water, cell_heights] : cases) {
    EXPECT_THAT(Solution().highestPeak(is_water), testing::ElementsAreArray(cell_heights));
  }
}
