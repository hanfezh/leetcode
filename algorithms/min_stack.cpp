// 155. Min Stack: https://leetcode.com/problems/min-stack
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <climits>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MinStack {
  struct Node {
    int val;
    int min;
    Node* next;
    Node(int _val, int _min, Node* _next = nullptr) : val(_val), min(_min), next(_next) {}
  };

 public:
  MinStack() : head_(nullptr) {}

  void push(int x) {
    if (head_ == nullptr) {
      head_ = new Node(x, x);
    } else {
      head_ = new Node(x, std::min(head_->min, x), head_);
    }
  }

  void pop() {
    auto* ptr = head_;
    head_ = head_->next;
    delete ptr;
  }

  int top() { return head_->val; }

  int getMin() { return head_->min; }

 private:
  Node* head_;
};

TEST(Solution, MinStack) {
  MinStack min_stack;
  min_stack.push(-2);
  min_stack.push(0);
  min_stack.push(-3);
  EXPECT_EQ(min_stack.getMin(), -3);

  min_stack.pop();
  EXPECT_EQ(min_stack.top(), 0);
  EXPECT_EQ(min_stack.getMin(), -2);
}
