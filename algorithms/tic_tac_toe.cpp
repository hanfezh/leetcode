/*
 * =====================================================================================
 *
 *       Filename:  tic_tac_toe.cpp
 *
 *    Description:  348. Design Tic-Tac-Toe.
 *                  https://leetcode.com/problems/design-tic-tac-toe/
 *
 *        Version:  1.0
 *        Created:  03/02/2024 16:51:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::tuple;
using std::vector;

class TicTacToe {
 public:
  TicTacToe(int n) : matrix_(n, vector<int>(n)) {}

  int move(int row, int col, int player) {
    const int n = matrix_.size();
    matrix_[row][col] = player;
    for (int i = 0; i < n; i++) {
      if (matrix_[row][i] != player) {
        break;
      }
      if (i == n - 1) {
        return player;
      }
    }
    for (int i = 0; i < n; i++) {
      if (matrix_[i][col] != player) {
        break;
      }
      if (i == n - 1) {
        return player;
      }
    }
    if (row == col) {
      for (int i = 0; i < n; i++) {
        if (matrix_[i][i] != player) {
          break;
        }
        if (i == n - 1) {
          return player;
        }
      }
    }
    if (row + col == n - 1) {
      for (int i = 0; i < n; i++) {
        if (matrix_[i][n - i - 1] != player) {
          break;
        }
        if (i == n - 1) {
          return player;
        }
      }
    }
    return 0;
  }

 private:
  vector<vector<int>> matrix_;
};

TEST(Solution, move2) {
  TicTacToe tic_tac_toe(2);
  vector<tuple<int, int, int, int>> moves = {
      std::make_tuple(0, 1, 1, 0),
      std::make_tuple(1, 1, 2, 0),
      std::make_tuple(1, 0, 1, 1),
  };
  for (auto& c : moves) {
    EXPECT_EQ(tic_tac_toe.move(std::get<0>(c), std::get<1>(c), std::get<2>(c)), std::get<3>(c));
  }
}

TEST(Solution, move3) {
  TicTacToe tic_tac_toe(3);
  vector<tuple<int, int, int, int>> moves = {
      std::make_tuple(0, 0, 1, 0), std::make_tuple(0, 2, 2, 0), std::make_tuple(2, 2, 1, 0),
      std::make_tuple(1, 1, 2, 0), std::make_tuple(2, 0, 1, 0), std::make_tuple(1, 0, 2, 0),
      std::make_tuple(2, 1, 1, 1),
  };
  for (auto& c : moves) {
    EXPECT_EQ(tic_tac_toe.move(std::get<0>(c), std::get<1>(c), std::get<2>(c)), std::get<3>(c));
  }
}
