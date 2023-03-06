/*
 * =====================================================================================
 *
 *       Filename:  k_closest_points.cpp
 *
 *    Description:  973. K Closest Points to Origin.
 *                  https://leetcode.com/problems/k-closest-points-to-origin/
 *
 *        Version:  1.0
 *        Created:  02/20/2023 19:40:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::priority_queue;
using std::vector;

// Sorting
class Solution1 {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    std::partial_sort(
        points.begin(), points.begin() + k, points.end(),
        [](const vector<int>& a, const vector<int>& b) {
          return ((a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]));
        });
    return {points.begin(), points.begin() + k};
  }
};

// Max heap
class Solution2 {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq(points.begin(),
                                                                 points.end());
    while (pq.size() > k) {
      pq.pop();
    }

    vector<vector<int>> res;
    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }
    return res;
  }

  struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
      return ((a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]));
    }
  };
};

TEST(Solution, kClosest) {
  vector<std::tuple<vector<vector<int>>, int, vector<vector<int>>>> cases = {
      std::make_tuple(vector<vector<int>>{{1, 3}, {-2, 2}}, 1,
                      vector<vector<int>>{{-2, 2}}),
      std::make_tuple(vector<vector<int>>{{3, 3}, {5, -1}, {-2, 4}}, 2,
                      vector<vector<int>>{{3, 3}, {-2, 4}}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution1().kClosest(std::get<0>(c), std::get<1>(c)),
                testing::ElementsAreArray(std::get<2>(c)));
    EXPECT_THAT(Solution2().kClosest(std::get<0>(c), std::get<1>(c)),
                testing::UnorderedElementsAreArray(std::get<2>(c)));
  }
}
