/*
 * =====================================================================================
 *
 *       Filename:  reorder_list.cpp
 *
 *    Description:  143. Reorder List. https://leetcode.com/problems/reorder-list
 *
 *        Version:  1.0
 *        Created:  10/24/2021 20:59:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Recursion
class Solution {
 public:
  void reorderList(ListNode* head) {
    ListNode* ptr = head;
    ListNode* tail = head;
    bool reordered = false;
    reorderList(head, tail, ptr, reordered);
  }

  void reorderList(ListNode*& head, ListNode* tail, ListNode*& ptr, bool& reordered) {
    if (tail == nullptr) {
      return;
    }
    reorderList(head, tail->next, ptr, reordered);
    if (reordered) {
      return;
    }
    if (head == tail || head->next == tail) {
      if (tail->next != nullptr) {
        tail->next = nullptr;
      }
      reordered = true;
      return;
    }
    head = head->next;
    tail->next = head;
    ptr->next = tail;
    ptr = head;
  }
};

int main(int argc, char* argv[]) {
  ListNode* head = nullptr;
  Solution().reorderList(head);
  return 0;
}
