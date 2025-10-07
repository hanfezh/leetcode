/*
 * =====================================================================================
 *
 *       Filename:  summary_ranges.cpp
 *
 *    Description:  228. Summary Ranges
 *                  https://leetcode.com/problems/summary-ranges/
 *
 *        Version:  1.0
 *        Created:  10/07/2025 14:59:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    if (nums.size() == 0) {
      return {};
    }

    auto convert = [](const int a, const int b) -> std::string {
      return a == b ? std::to_string(a) : (std::to_string(a) + "->" + std::to_string(b));
    };

    std::vector<std::string> ranges;
    std::pair<int, int> last = {nums[0], nums[0]};
    for (int val : nums) {
      if (val == last.second + 1) {
        last.second++;
      } else if (val != last.second) {
        ranges.push_back(convert(last.first, last.second));
        last = {val, val};
      }
    }
    ranges.push_back(convert(last.first, last.second));
    return ranges;
  }
};

TEST(Solution, summaryRanges) {
  std::vector<std::pair<std::vector<int>, std::vector<std::string>>> cases = {
      {{0, 1, 2, 4, 5, 7}, {"0->2", "4->5", "7"}},
      {{0, 2, 3, 4, 6, 8, 9}, {"0", "2->4", "6", "8->9"}},
  };
  for (auto& [nums, ranges] : cases) {
    EXPECT_EQ(Solution().summaryRanges(nums), ranges);
  }
}
