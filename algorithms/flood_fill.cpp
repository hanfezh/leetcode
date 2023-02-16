/*
 * =====================================================================================
 *
 *       Filename:  flood_fill.cpp
 *
 *    Description:  733. Flood Fill. https://leetcode.com/problems/flood-fill/
 *
 *        Version:  1.0
 *        Created:  02/16/2023 09:55:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

// Depth first search
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image.size() == 0 || image[0].size() == 0) {
      return image;
    }

    const int source = image[sr][sc];
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
    innerFill(image, visited, sr, sc, source, color);
    return image;
  }

  void innerFill(vector<vector<int>>& image, vector<vector<bool>>& visited, int i, int j,
                 int source, int target) {
    const int m = image.size();
    const int n = image[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return;
    }
    if (visited[i][j]) {
      return;
    }
    if (image[i][j] != source) {
      return;
    }

    image[i][j] = target;
    visited[i][j] = true;
    innerFill(image, visited, i - 1, j, source, target);
    innerFill(image, visited, i + 1, j, source, target);
    innerFill(image, visited, i, j - 1, source, target);
    innerFill(image, visited, i, j + 1, source, target);
  }
};

TEST(Solution, floodFill) {
  vector<std::tuple<vector<vector<int>>, int, int, int, vector<vector<int>>>> cases = {
      std::make_tuple(
          vector<vector<int>>{
              {1, 1, 1},
              {1, 1, 0},
              {1, 0, 1},
          },
          1, 1, 2,
          vector<vector<int>>{
              {2, 2, 2},
              {2, 2, 0},
              {2, 0, 1},
          }),
      std::make_tuple(
          vector<vector<int>>{
              {0, 0, 0},
              {0, 0, 0},
          },
          0, 0, 0,
          vector<vector<int>>{
              {0, 0, 0},
              {0, 0, 0},
          }),
  };
  for (auto& c : cases) {
    EXPECT_THAT(
        Solution().floodFill(std::get<0>(c), std::get<1>(c), std::get<2>(c), std::get<3>(c)),
        testing::ElementsAreArray(std::get<4>(c)));
  }
}
