/*
 * =====================================================================================
 *
 *       Filename:  sort_characters_by_frequency.cpp
 *
 *    Description:  451. Sort Characters By Frequency
 *                  https://leetcode.com/problems/sort-characters-by-frequency/
 *
 *        Version:  1.0
 *        Created:  02/22/2022 22:11:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Hash table without sort
class Solution1 {
 public:
  std::string frequencySort(const std::string& s) {
    // Count frequency
    std::unordered_map<char, int> freq;
    for (const char c : s) {
      freq[c]++;
    }

    // Gather characters with same frequency
    std::vector<std::string> bucket(s.size() + 1);
    for (const auto& item : freq) {
      bucket[item.second].append(1, item.first);
    }

    // Assemble sorted string
    std::string res;
    for (int i = bucket.size() - 1; i > 0; i--) {
      if (bucket[i].empty()) {
        continue;
      }
      for (char c : bucket[i]) {
        res.append(i, c);
      }
    }
    return res;
  }
};

// Hash table with sort
class Solution2 {
 public:
  std::string frequencySort(std::string s) {
    std::vector<int> counts(128, 0);
    for (const char c : s) {
      counts[c]++;
    }
    std::sort(s.begin(), s.end(), [&](const char a, const char b) -> bool {
      return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
    });
    return s;
  }
};

TEST(Solution, frequencySort) {
  std::vector<std::pair<std::string, std::string>> cases = {
      std::make_pair("tree", "eert"),
      std::make_pair("cccaaa", "aaaccc"),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().frequencySort(c.first), c.second);
    EXPECT_EQ(Solution2().frequencySort(c.first), c.second);
  }
}
