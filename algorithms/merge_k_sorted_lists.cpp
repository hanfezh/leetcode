/*
 * =====================================================================================
 *
 *       Filename:  merge_k_sorted_lists.cpp
 *
 *    Description:  23. Merge k Sorted Lists. Merge k sorted linked lists and return it
 *                  as one sorted list. Analyze and describe its complexity.
 *
 *        Version:  1.0
 *        Created:  04/16/19 01:42:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    ListNode* first = nullptr;
    for (int i = 0; i < lists.size(); i++) {
      first = mergeList(first, lists[i]);
    }

    return first;
  }

 private:
  ListNode* mergeList(ListNode* a, ListNode* b) {
    ListNode fake(0);
    ListNode* ptr = &fake;
    while (a != nullptr && b != nullptr) {
      ListNode* tmp = nullptr;
      if (a->val < b->val) {
        tmp = a;
        a = a->next;
      } else {
        tmp = b;
        b = b->next;
      }
      ptr->next = tmp;
      ptr = ptr->next;
      ptr->next = nullptr;
    }

    if (a != nullptr) {
      ptr->next = a;
    } else if (b != nullptr) {
      ptr->next = b;
    }

    return fake.next;
  }
};

int main(int argc, char* argv[]) {
  std::vector<ListNode*> lists;
  auto* sorted = Solution().mergeKLists(lists);
  return 0;
}
