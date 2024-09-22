/*
 * =====================================================================================
 *
 *       Filename:  stable_mountains.cpp
 *
 *    Description:  3285. Find Indices of Stable Mountains
 *
 *        Version:  1.0
 *        Created:  09/22/2024 15:26:40
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

using std::tuple;
using std::vector;

class Solution {
 public:
  vector<int> stableMountains(vector<int>& height, int threshold) {
    vector<int> indices;
    indices.reserve(height.size());
    for (int i = 1; i < height.size(); i++) {
      if (height[i - 1] > threshold) {
        indices.push_back(i);
      }
    }
    return indices;
  }
};

TEST(Solution, stableMountains) {
  vector<tuple<vector<int>, int, vector<int>>> cases = {
      std::make_tuple(vector<int>{1, 2, 3, 4, 5}, 2, vector<int>{3, 4}),
      std::make_tuple(vector<int>{10, 1, 10, 1, 10}, 3, vector<int>{1, 3}),
      std::make_tuple(vector<int>{10, 1, 10, 1, 10}, 10, vector<int>{}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().stableMountains(std::get<0>(c), std::get<1>(c)),
                testing::ElementsAreArray(std::get<2>(c)));
  }
}
