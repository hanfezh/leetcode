/*
 * =====================================================================================
 *
 *       Filename:  sample_stats.cpp
 *
 *    Description:  1093. Statistics from a Large Sample.
 *                  https://leetcode.com/problems/statistics-from-a-large-sample/
 *
 *        Version:  1.0
 *        Created:  03/03/23 23:31:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <numeric>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class Solution {
 public:
  vector<double> sampleStats(vector<int>& count) {
    int min_stat = 255, max_stat = 0, mode = 0;
    int64_t sum = 0;
    double median = 0.0;
    int cur_cnt = 0;
    int max_cnt = 0;
    int total_cnt = std::accumulate(count.begin(), count.end(), 0);
    int m1 = (total_cnt + 1) / 2;
    int m2 = (total_cnt % 2 == 0) ? (m1 + 1) : m1;
    for (int i = 0; i < count.size(); i++) {
      if (count[i] <= 0) {
        continue;
      }

      min_stat = std::min(min_stat, i);
      max_stat = std::max(max_stat, i);
      sum += (int64_t)i * count[i];

      if ((cur_cnt < m1) && (cur_cnt + count[i] >= m1)) {
        median = (double)i / 2;
      }
      if ((cur_cnt < m2) && (cur_cnt + count[i] >= m2)) {
        median += (double)i / 2;
      }
      cur_cnt += count[i];

      if (count[i] > max_cnt) {
        mode = i;
        max_cnt = count[i];
      }
    }
    return {(double)min_stat, (double)max_stat, (double)sum / total_cnt, median,
            (double)mode};
  }
};

TEST(Solution, sampleStats) {
  vector<std::pair<vector<int>, vector<double>>> cases = {
      std::make_pair(
          vector<int>{
              0, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          vector<double>{1.00000, 3.00000, 2.37500, 2.50000, 3.00000}),
      /* std::make_pair(
          vector<int>{
              0, 4, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          vector<double>{1.00000, 4.00000, 2.18182, 2.00000, 1.00000}), */
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().sampleStats(c.first),
                testing::ElementsAreArray(c.second));
  }
}
