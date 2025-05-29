/*
 * =====================================================================================
 *
 *       Filename:  min_operations.cpp
 *
 *    Description:  1769. Minimum Number of Operations to Move All Balls to Each Box
 *
 *        Version:  1.0
 *        Created:  05/30/2025 07:16:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution {
 public:
  std::vector<int> minOperations(std::string boxes) {
    int left_balls = 0;
    int left_moves = 0;
    int right_balls = 0;
    int right_moves = 0;
    std::vector<int> answer(boxes.size(), 0);

    for (int i = boxes.size() - 1; i >= 0; i--) {
      right_moves += right_balls;
      if (boxes[i] == '1') {
        right_balls++;
      }
    }
    for (int i = 0; i < boxes.size(); i++) {
      answer[i] = left_moves + right_moves;
      if (boxes[i] == '1') {
        left_balls++;
        right_balls--;
      }
      left_moves += left_balls;
      right_moves -= right_balls;
    }
    return answer;
  }
};

TEST(Solution, minOperations) {
  std::vector<std::pair<std::string, std::vector<int>>> cases = {
      {"110", {1, 1, 3}},
      {"001011", {11, 8, 5, 4, 3, 4}},
  };
  for (auto& [boxes, answer] : cases) {
    EXPECT_THAT(Solution().minOperations(boxes), testing::ElementsAreArray(answer));
  }
}
