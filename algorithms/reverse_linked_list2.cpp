/*
 * =====================================================================================
 *
 *       Filename:  reverse_linked_list2.cpp
 *
 *    Description:  92. Reverse Linked List II.
 *
 *        Version:  1.0
 *        Created:  04/11/19 03:39:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  // 1 <= left <= right <= n
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode fake(0);
    ListNode* pre = &fake;
    ListNode* cur = head;
    fake.next = head;

    while (--left > 0) {
      pre = cur;
      cur = cur->next;
      right--;
    }
    pre->next = nullptr;

    ListNode* last = cur;
    ListNode* tmp = nullptr;
    while (right > 0) {
      tmp = cur->next;
      cur->next = pre->next;
      pre->next = cur;
      cur = tmp;
      right--;
    }
    if (last != cur) {
      last->next = cur;
    }

    return fake.next;
  }
};

int main(int argc, char* argv[]) {
  ListNode head(0);
  auto* reverse = Solution().reverseBetween(&head, 0, 0);
  return 0;
}
