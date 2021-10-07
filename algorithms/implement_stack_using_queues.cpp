/*
 * =====================================================================================
 *
 *       Filename:  implement_stack_using_queues.cpp
 *
 *    Description:  225. Implement Stack using Queues.
 *                  https://leetcode.com/problems/implement-stack-using-queues
 *
 *        Version:  1.0
 *        Created:  10/07/2021 22:26:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <queue>

class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    while (!queue2_.empty()) {
      queue1_.push(queue2_.front());
      queue2_.pop();
    }
    queue1_.swap(queue2_);
    queue1_.push(x);
  }

  int pop() {
    int val = -1;
    if (!queue1_.empty()) {
      val = queue1_.front();
      queue1_.pop();
    } else {
      val = queue2_.front();
      queue2_.pop();
    }
    return val;
  }

  int top() {
    if (!queue1_.empty()) {
      return queue1_.front();
    }
    return queue2_.front();
  }

  bool empty() { return (queue1_.empty() && queue2_.empty()); }

 private:
  std::queue<int> queue1_;
  std::queue<int> queue2_;
};

int main(int argc, char* argv[]) {
  MyStack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  printf("top is %d\n", stack.top());
  return 0;
}
