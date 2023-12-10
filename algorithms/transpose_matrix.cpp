/*
 * =====================================================================================
 *
 *       Filename:  transpose_matrix.cpp
 *
 *    Description:  867. Transpose Matrix
 *
 *        Version:  1.0
 *        Created:  12/10/2023 15:29:04
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

using std::pair;
using std::vector;

class Solution {
 public:
  vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return matrix;
    }

    vector<vector<int>> trans(matrix[0].size(), vector<int>(matrix.size()));
    for (int i = 0; i < trans.size(); i++) {
      for (int j = 0; j < trans[i].size(); j++) {
        trans[i][j] = matrix[j][i];
      }
    }
    return trans;
  }
};

TEST(Solution, transpose) {
  vector<pair<vector<vector<int>>, vector<vector<int>>>> cases = {
      std::make_pair(
          vector<vector<int>>{
              {1, 2, 3},
              {4, 5, 6},
              {7, 8, 9},
          },
          vector<vector<int>>{
              {1, 4, 7},
              {2, 5, 8},
              {3, 6, 9},
          }),
      std::make_pair(
          vector<vector<int>>{
              {1, 2, 3},
              {4, 5, 6},
          },
          vector<vector<int>>{
              {1, 4},
              {2, 5},
              {3, 6},
          }),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().transpose(c.first), testing::ElementsAreArray(c.second));
  }
}
