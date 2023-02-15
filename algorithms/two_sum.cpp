// 1. Two Sum: https://leetcode.com/problems/two-Sum
// Author: xianfeng.zhu@gmail.com
#include <tuple>
#include <unordered_map>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> indices;
    for (int i = 0; i < nums.size(); i++) {
      auto iter = indices.find(target - nums[i]);
      if (iter != indices.end()) {
        return std::vector<int>({iter->second, i});
      } else {
        indices[nums[i]] = i;
      }
    }
    return std::vector<int>();
  }
};

TEST(Solution, twoSum) {
  std::vector<std::tuple<std::vector<int>, int, std::vector<int>>> cases = {
      std::make_tuple(std::vector<int>{2, 7, 11, 15}, 9, std::vector<int>{0, 1}),
      std::make_tuple(std::vector<int>{3, 2, 4}, 6, std::vector<int>{1, 2}),
      std::make_tuple(std::vector<int>{3, 3}, 6, std::vector<int>{0, 1}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().twoSum(std::get<0>(c), std::get<1>(c)),
                testing::ElementsAreArray(std::get<2>(c)));
  }
}
