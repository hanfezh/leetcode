/*
 * =====================================================================================
 *
 *       Filename:  count_battleships.cpp
 *
 *    Description:  419. Battleships in a Board
 *
 *        Version:  1.0
 *        Created:  11/11/2025 10:58:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <utility>
#include <vector>

#include "gtest/gtest.h"

// Time complexity: O(m*n)
// Space complexity: O(1)
class Solution {
 public:
  int countBattleships(std::vector<std::vector<char>>& board) {
    int count = 0;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == 'X') {
          if (i > 0 && board[i - 1][j] == 'X') {
            continue;
          }
          if (j > 0 && board[i][j - 1] == 'X') {
            continue;
          }
          count++;
        }
      }
    }
    return count;
  }
};

TEST(Solution, countBattleships) {
  std::vector<std::pair<std::vector<std::vector<char>>, int>> cases = {
      {{{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}}, 2},
      {{{'.'}}, 0},
  };
  for (auto& [board, count] : cases) {
    EXPECT_EQ(Solution().countBattleships(board), count);
  }
}
