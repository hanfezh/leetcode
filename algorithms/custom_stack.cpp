/*
 * =====================================================================================
 *
 *       Filename:  custom_stack.cpp
 *
 *    Description:  1381. Design a Stack With Increment Operation.
 *                  https://leetcode.com/problems/design-a-stack-with-increment-operation/
 *
 *        Version:  1.0
 *        Created:  03/09/23 21:45:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class CustomStack {
 public:
  CustomStack(int max_size) : size_(max_size) {}

  void push(int x) {
    if (nums_.size() < size_) {
      nums_.push_back(x);
    }
  }

  int pop() {
    if (nums_.empty()) {
      return -1;
    }
    const int val = nums_.back();
    nums_.pop_back();
    return val;
  }

  void increment(int k, int val) {
    if (k > nums_.size()) {
      k = nums_.size();
    }
    for (int i = 0; i < k; i++) {
      nums_[i] += val;
    }
  }

 private:
  vector<int> nums_;
  int size_;
};

TEST(Solution, CustomStack) {
  CustomStack stk(3);         // Stack is Empty []
  stk.push(1);                // stack becomes [1]
  stk.push(2);                // stack becomes [1, 2]
  EXPECT_EQ(stk.pop(), 2);    // return 2, stack becomes [1]
  stk.push(2);                // stack becomes [1, 2]
  stk.push(3);                // stack becomes [1, 2, 3]
  stk.push(4);                // stack still [1, 2, 3]
  stk.increment(5, 100);      // stack becomes [101, 102, 103]
  stk.increment(2, 100);      // stack becomes [201, 202, 103]
  EXPECT_EQ(stk.pop(), 103);  // return 103, stack becomes [201, 202]
  EXPECT_EQ(stk.pop(), 202);  // return 202, stack becomes [201]
  EXPECT_EQ(stk.pop(), 201);  // return 201, stack becomes []
  EXPECT_EQ(stk.pop(), -1);   // return -1, stack is empty
}
