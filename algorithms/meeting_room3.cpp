/*
 * =====================================================================================
 *
 *       Filename:  meeting_room3.cpp
 *
 *    Description:  2402. Meeting Rooms III
 *
 *        Version:  1.0
 *        Created:  11/16/2025 21:25:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

// Priority queue
// Time complexity: O(mlogn)
// Space complexity: O(n)
class Solution {
 public:
  int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
    // Available rooms
    std::set<int> available;
    for (int i = 0; i < n; i++) {
      available.insert(i);
    }

    // The number held meetings
    std::vector<int> count(n, 0);
    int max_cnt = 0;

    // Min heap: {available time, room}
    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>,
                        std::greater<std::pair<int64_t, int>>>
        busy;

    // Ensure meetings are sorted ascending by unique start time
    std::sort(
        meetings.begin(), meetings.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) -> bool { return a[0] < b[0]; });

    const int m = meetings.size();
    for (int i = 0; i < m; i++) {
      int64_t t = meetings[i][0];
      while (!busy.empty() && busy.top().first <= t) {
        available.insert(busy.top().second);
        busy.pop();
      }

      int j = 0;
      if (!available.empty()) {
        // Choose the first room
        j = *available.begin();
        available.erase(available.begin());
      } else {
        // No available room and pick the first from busy queue
        std::tie(t, j) = busy.top();
        busy.pop();
      }

      busy.push({t + meetings[i][1] - meetings[i][0], j});
      max_cnt = std::max(max_cnt, ++count[j]);
    }

    int busiest = 0;
    for (int i = 0; i < n; i++) {
      if (count[i] == max_cnt) {
        busiest = i;
        break;
      }
    }
    return busiest;
  }
};

TEST(Solution, mostBooked) {
  std::vector<std::tuple<int, std::vector<std::vector<int>>, int>> cases = {
      {2, {{0, 10}, {1, 5}, {2, 7}, {3, 4}}, 0},
      {3, {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}}, 1},
      {3, {{0, 10}, {1, 9}, {2, 8}, {3, 7}, {4, 6}}, 1},
  };
  for (auto& [n, meetings, res] : cases) {
    EXPECT_EQ(Solution().mostBooked(n, meetings), res);
  }
}
