/*
 * =====================================================================================
 *
 *       Filename:  top_k_frequent_elements.cpp
 *
 *    Description:  347. Top K Frequent Elements.
 *                  https://leetcode.com/problems/top-k-frequent-elements/
 *
 *        Version:  1.0
 *        Created:  03/07/23 16:07:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <queue>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::pair;
using std::priority_queue;
using std::tuple;
using std::unordered_map;
using std::vector;

class Solution {
  using value_type = pair<int, int>;

  struct Compare {
    bool operator()(const value_type& a, const value_type& b) {
      return a.second < b.second;
    }
  };

 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for (const int n : nums) {
      counts[n]++;
    }

    priority_queue<value_type, vector<value_type>, Compare> pq;
    for (const auto& kv : counts) {
      pq.push(std::make_pair(kv.first, kv.second));
    }

    vector<int> res;
    while (k-- > 0) {
      res.push_back(pq.top().first);
      pq.pop();
    }
    return res;
  }
};

TEST(Solution, topKFrequent) {
  vector<tuple<vector<int>, int, vector<int>>> cases = {
      std::make_tuple(vector<int>{1}, 1, vector<int>{1}),
      std::make_tuple(vector<int>{1, 1, 1, 2, 2, 3}, 2, vector<int>{1, 2}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().topKFrequent(std::get<0>(c), std::get<1>(c)),
                testing::ElementsAreArray(std::get<2>(c)));
  }
}
