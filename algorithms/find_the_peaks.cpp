/*
 * =====================================================================================
 *
 *       Filename:  find_the_peaks.cpp
 *
 *    Description:  2951. Find the Peaks. https://leetcode.com/problems/find-the-peaks/
 *
 *        Version:  1.0
 *        Created:  12/09/2023 20:02:42
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
  vector<int> findPeaks(vector<int>& mountain) {
    vector<int> peaks;
    peaks.reserve(mountain.size());
    for (int i = 1; i < mountain.size() - 1; i++) {
      if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
        peaks.push_back(i);
      }
    }
    return peaks;
  }
};

TEST(Solution, findPeaks) {
  vector<pair<vector<int>, vector<int>>> cases = {
      std::make_pair(vector<int>{2, 4, 4}, vector<int>{}),
      std::make_pair(vector<int>{1, 4, 3, 8, 5}, vector<int>{1, 3}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().findPeaks(c.first), testing::ElementsAreArray(c.second));
  }
}
