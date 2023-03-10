/*
 * =====================================================================================
 *
 *       Filename:  linked_list_random_node.cpp
 *
 *    Description:  382. Linked List Random Node.
 *                  https://leetcode.com/problems/linked-list-random-node/
 *
 *        Version:  1.0
 *        Created:  03/10/23 10:12:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdlib>
#include <ctime>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  Solution(ListNode* head) : head_(head), size_(0) {
    ListNode* p = head;
    while (p != nullptr) {
      size_++;
      p = p->next;
    }
    std::srand(std::time(0));
  }

  int getRandom() {
    int num = std::rand() % size_;
    ListNode* p = head_;
    while (num-- > 0) {
      p = p->next;
    }
    return p->val;
  }

 private:
  ListNode* head_;
  int size_;
};

TEST(Solution, getRandom) {
  ListNode* head = new ListNode(1);
  EXPECT_EQ(Solution(head).getRandom(), 1);
}
