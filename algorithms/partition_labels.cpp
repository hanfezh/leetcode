/*
 * =====================================================================================
 *
 *       Filename:  partition_labels.cpp
 *
 *    Description:  763. Partition Labels
 *                  https://leetcode.com/problems/partition-labels/
 *
 *        Version:  1.0
 *        Created:  07/12/2025 22:53:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution {
 public:
  std::vector<int> partitionLabels(std::string s) {
    std::unordered_map<char, int> indexes;
    for (int i = 0; i < s.length(); i++) {
      indexes[s[i]] = i;
    }

    std::vector<int> parts;
    int prev = -1;
    int last = 0;
    for (int i = 0; i < s.length(); i++) {
      last = std::max(last, indexes[s[i]]);
      if (last == i) {
        parts.push_back(last - prev);
        prev = i;
        last = i + 1;
      }
    }
    if (last == s.length() - 1) {
      parts.push_back(last - prev);
    }
    return parts;
  }
};

TEST(Solution, partitionLabels) {
  std::vector<std::pair<std::string, std::vector<int>>> cases = {
      {"ababcbacadefegdehijhklij", {9, 7, 8}},
      {"eccbbbbdec", {10}},
  };
  for (auto& [s, parts] : cases) {
    EXPECT_THAT(Solution().partitionLabels(s), testing::ElementsAreArray(parts));
  }
}
