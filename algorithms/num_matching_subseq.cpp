/*
 * =====================================================================================
 *
 *       Filename:  num_matching_subseq.cpp
 *
 *    Description:  792. Number of Matching Subsequences
 *
 *        Version:  1.0
 *        Created:  11/12/2025 11:34:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

// Time complexity: O(mlogn)
// Space complexity: O(n)
class Solution {
 public:
  int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
    const int n = s.length();
    std::unordered_map<char, std::set<int>> indexes;
    for (int i = 0; i < n; i++) {
      indexes[s[i]].insert(i);
    }

    int res = 0;
    for (const auto& w : words) {
      const int m = w.length();
      if (m > n) {
        continue;
      }

      int start = -1;
      for (int i = 0; i < m; i++) {
        auto it1 = indexes.find(w[i]);
        if (it1 == indexes.end()) {
          break;
        }
        auto it2 = it1->second.upper_bound(start);
        if (it2 == it1->second.end()) {
          break;
        }
        start = *it2;
        if (i == m - 1) {
          res++;
        }
      }
    }

    return res;
  }
};

TEST(Solution, numMatchingSubseq) {
  std::vector<std::tuple<std::string, std::vector<std::string>, int>> cases = {
      {"abcde", {"a", "bb", "acd", "ace"}, 3},
      {"dsahjpjauf", {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"}, 2},
  };
  for (auto& [s, words, res] : cases) {
    EXPECT_EQ(Solution().numMatchingSubseq(s, words), res);
  }
}
