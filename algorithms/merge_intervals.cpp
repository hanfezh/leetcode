/*
 * =====================================================================================
 *
 *       Filename:  merge_intervals.cpp
 *
 *    Description:  56. Merge Intervals.
 *                  Given a collection of intervals, merge all overlapping intervals.
 *
 *        Version:  1.0
 *        Created:  04/11/19 01:39:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool operator==(const Interval& a, const Interval& b) {
  return (a.start == b.start && a.end == b.end);
}

class Solution {
 public:
  std::vector<Interval> merge(std::vector<Interval>& intervals) {
    auto cmp_func = [](const Interval& a, const Interval& b) -> bool { return a.start < b.start; };
    std::sort(intervals.begin(), intervals.end(), cmp_func);

    std::vector<Interval> merges;
    for (int i = 0; i < intervals.size();) {
      int low = intervals[i].start;
      int high = intervals[i].end;
      int next = i + 1;
      while ((next < intervals.size()) && (intervals[next].start <= high)) {
        high = std::max(high, intervals[next].end);
        next++;
      }

      i = next;
      merges.push_back(Interval(low, high));
    }

    return merges;
  }
};

TEST(Solution, merge) {
  vector<pair<vector<Interval>, vector<Interval>>> cases = {
      make_pair(vector<Interval>{{1, 3}, {2, 6}, {8, 10}, {15, 18}},
                vector<Interval>{{1, 6}, {8, 10}, {15, 18}}),
      make_pair(vector<Interval>{{1, 4}, {4, 5}}, vector<Interval>{{1, 5}}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().merge(c.first), testing::UnorderedElementsAreArray(c.second));
  }
}
