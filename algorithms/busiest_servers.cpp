/*
 * =====================================================================================
 *
 *       Filename:  busiest_servers.cpp
 *
 *    Description:  1606. Find Servers That Handled Most Number of Requests
 *
 *        Version:  1.0
 *        Created:  11/14/2025 22:05:17
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
#include <vector>

#include "gtest/gtest.h"

// Time complexity: O(nlog(k))
// Space complexity: O(k)
class Solution {
 public:
  std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
    // Available servers
    std::set<int> available;
    for (int i = 0; i < k; i++) {
      available.insert(i);
    }

    // Min heap: {available time, server number}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        busy;
    std::vector<int> count(k, 0);
    int max_cnt = 0;

    const int n = arrival.size();
    for (int i = 0; i < n; i++) {
      int t = arrival[i];
      while (!busy.empty() && busy.top().first <= t) {
        available.insert(busy.top().second);
        busy.pop();
      }

      if (available.empty()) {
        // Drop it if all servers are busy
        continue;
      }

      // Find available server >= start
      int start = i % k;
      auto it = available.lower_bound(start);
      if (it == available.end()) {
        // Choose the first
        it = available.begin();
      }

      int svr = *it;
      count[svr]++;
      max_cnt = std::max(max_cnt, count[svr]);
      busy.push({t + load[i], svr});
      available.erase(it);
    }

    std::vector<int> res;
    for (int i = 0; i < count.size(); i++) {
      if (count[i] == max_cnt) {
        res.push_back(i);
      }
    }
    return res;
  }
};

TEST(Solution, busiestServers) {
  std::vector<std::tuple<int, std::vector<int>, std::vector<int>, std::vector<int>>> cases = {
      {3, {1, 2, 3, 4, 5}, {5, 2, 3, 3, 3}, {1}},
      {3, {1, 2, 3, 4}, {1, 2, 1, 2}, {0}},
      {3, {1, 2, 3}, {10, 12, 11}, {0, 1, 2}},
  };
  for (auto& [k, arrival, load, res] : cases) {
    EXPECT_EQ(Solution().busiestServers(k, arrival, load), res);
  }
}
