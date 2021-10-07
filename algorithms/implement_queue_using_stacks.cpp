/*
 * =====================================================================================
 *
 *       Filename:  implement_queue_using_stacks.cpp
 *
 *    Description:  232. Implement Queue using Stacks.
 *                  https://leetcode.com/problems/implement-queue-using-stacks
 *
 *        Version:  1.0
 *        Created:  10/07/2021 17:27:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <stack>

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { stack1_.push(x); }

  int pop() {
    const int val = peek();
    stack2_.pop();
    return val;
  }

  int peek() {
    if (stack2_.empty()) {
      while (!stack1_.empty()) {
        stack2_.push(stack1_.top());
        stack1_.pop();
      }
    }
    return stack2_.top();
  }

  bool empty() { return (stack1_.empty() && stack2_.empty()); }

 private:
  std::stack<int> stack1_;
  std::stack<int> stack2_;
};

int main(int argc, char* argv[]) {
  MyQueue queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  const int val = queue.peek();
  printf("val = %d\n", val);
  return 0;
}
