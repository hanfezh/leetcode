/*
 * =====================================================================================
 *
 *       Filename:  max_stack.cpp
 *
 *    Description:  716. Max Stack. https://leetcode.com/problems/max-stack/
 *
 *        Version:  1.0
 *        Created:  06/15/2024 21:48:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <set>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MaxStack {
 public:
  MaxStack() {}

  void push(int x) {
    int index = 0;
    if (stack_.size() > 0) {
      index = stack_.rbegin()->first + 1;
    }
    stack_.emplace(std::make_pair(index, x));
    queue_.emplace(std::make_pair(x, index));
  }

  int pop() {
    auto back = std::prev(stack_.end());
    const int val = back->second;
    queue_.erase(std::make_pair(back->second, back->first));
    stack_.erase(back);
    return val;
  }

  int top() { return stack_.rbegin()->second; }

  int peekMax() { return queue_.rbegin()->first; }

  int popMax() {
    auto back = std::prev(queue_.end());
    const int val = back->first;
    stack_.erase(std::make_pair(back->second, back->first));
    queue_.erase(back);
    return val;
  }

 private:
  std::set<std::pair<int, int>> stack_;  // index, value
  std::set<std::pair<int, int>> queue_;  // value, index
};

TEST(MaxStack, push) {
  MaxStack* obj = new MaxStack();
  obj->push(5);
  obj->push(1);
  obj->push(5);
  EXPECT_EQ(obj->pop(), 5);
  EXPECT_EQ(obj->top(), 1);
  EXPECT_EQ(obj->peekMax(), 5);
  EXPECT_EQ(obj->popMax(), 5);
  EXPECT_EQ(obj->top(), 1);
}
