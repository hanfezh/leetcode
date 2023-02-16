/*
 * =====================================================================================
 *
 *       Filename:  middle_node.cpp
 *
 *    Description:  876. Middle of the Linked List.
 *                  https://leetcode.com/problems/middle-of-the-linked-list/
 *
 *        Version:  1.0
 *        Created:  02/16/2023 17:53:52
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

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  static ListNode* convert(const std::vector<int>& nums) {
    ListNode dummy;
    ListNode* ptr = &dummy;
    for (int n : nums) {
      ptr->next = new ListNode(n);
      ptr = ptr->next;
    }
    return dummy.next;
  }
};

// Two pointers
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (slow != nullptr && fast != nullptr) {
      if (fast->next == nullptr) {
        break;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

TEST(Solution, middleNode) {
  std::vector<std::pair<ListNode*, int>> cases = {
      std::make_pair(ListNode::convert(std::vector<int>{1, 2, 3, 4, 5}), 3),
      std::make_pair(ListNode::convert(std::vector<int>{1, 2, 3, 4, 5, 6}), 4),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().middleNode(c.first)->val, c.second);
  }
}
