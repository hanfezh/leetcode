// =====================================================================================
//
//       Filename:  insert_interval.cpp
//
//    Description:  57. Insert Interval.
//                  Given a set of non-overlapping intervals, insert a new interval into
//                  the intervals (merge if necessary). You may assume that the intervals
//                  were initially sorted according to their start times.
//
//        Version:  1.0
//        Created:  10/16/2019 04:48:29 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:
//
// =====================================================================================
#include <algorithm>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class Solution1 {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval) {
    vector<vector<int>> merged_intervals;
    bool not_pushed = true;
    int start = new_interval[0];
    int end = new_interval[1];

    for (const auto& item : intervals) {
      if (item[1] < new_interval[0]) {
        // Current item if at left of new_interval
        merged_intervals.push_back(item);
      } else if (item[0] > new_interval[1]) {
        // Current item is at right of new_interval
        if (not_pushed) {
          merged_intervals.push_back(vector<int>({start, end}));
          not_pushed = false;
        }
        merged_intervals.push_back(item);
      } else {
        // Current item is overlapping with new_interval
        start = std::min(start, item[0]);
        end = std::max(end, item[1]);
      }
    }

    if (not_pushed) {
      merged_intervals.push_back(vector<int>({start, end}));
    }
    return merged_intervals;
  }
};

// Time complexity: O(n)
class Solution2 {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval) {
    std::vector<std::vector<int>> merges;
    int i = 0;

    // No overlapping before merging the new interval
    while (i < intervals.size() && intervals[i][1] < new_interval[0]) {
      merges.push_back(intervals[i++]);
    }

    // Overlapping
    while (i < intervals.size() && intervals[i][0] <= new_interval[1]) {
      new_interval[0] = std::min(new_interval[0], intervals[i][0]);
      new_interval[1] = std::max(new_interval[1], intervals[i][1]);
      i++;
    }
    merges.push_back(new_interval);

    // No overlapping after merge
    while (i < intervals.size()) {
      merges.push_back(intervals[i++]);
    }
    return merges;
  }
};

TEST(Solution, insert) {
  vector<std::tuple<vector<vector<int>>, vector<int>, vector<vector<int>>>> cases = {
      std::make_tuple(vector<vector<int>>{vector<int>{1, 3}, vector<int>{6, 9}}, vector<int>{2, 5},
                      vector<vector<int>>{vector<int>{1, 5}, vector<int>{6, 9}}),
      std::make_tuple(
          vector<vector<int>>{vector<int>{1, 2}, vector<int>{3, 5}, vector<int>{6, 7},
                              vector<int>{8, 10}, vector<int>{12, 16}},
          vector<int>{4, 8},
          vector<vector<int>>{vector<int>{1, 2}, vector<int>{3, 10}, vector<int>{12, 16}}),
  };
  for (auto& [intervals, new_interval1, merges] : cases) {
    auto new_interval2 = new_interval1;
    EXPECT_THAT(Solution1().insert(intervals, new_interval1), testing::ElementsAreArray(merges));
    EXPECT_THAT(Solution2().insert(intervals, new_interval2), testing::ElementsAreArray(merges));
  }
}
