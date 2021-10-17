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
#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

// Merge lists one by one, O(kN)
class Solution1 {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
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

// Priority queue, O(Nlogk)
class Solution2 {
 public:
  struct NodeCompare {
    bool operator()(const ListNode* a, const ListNode* b) { return a->val > b->val; }
  };

  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, NodeCompare> min_queue;
    for (auto lst : lists) {
      if (lst != nullptr) {
        min_queue.push(lst);
      }
    }

    if (min_queue.empty()) {
      return nullptr;
    }

    ListNode dummy(0);
    ListNode* ptr = &dummy;
    while (!min_queue.empty()) {
      ptr->next = min_queue.top();
      ptr = ptr->next;
      min_queue.pop();
      if (ptr->next != nullptr) {
        min_queue.push(ptr->next);
      }
    }
    return dummy.next;
  }
};

using Solution = Solution2;

int main(int argc, char* argv[]) {
  std::vector<ListNode*> lists;
  auto* sorted = Solution().mergeKLists(lists);
  return 0;
}
