/*
 * =====================================================================================
 *
 *       Filename:  sort_list.cpp
 *
 *    Description:  148. Sort List.
 *                  Sort a linked list in O(nlogn) time using constant space complexity.
 *
 *        Version:  1.0
 *        Created:  04/11/19 11:24:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createList(const std::vector<int>& nums) {
  ListNode dummy;
  ListNode* p = &dummy;
  for (const int n : nums) {
    p->next = new ListNode(n);
    p = p->next;
  }
  return dummy.next;
}

void deleteList(ListNode* head) {
  ListNode* ptr = nullptr;
  while (head != nullptr) {
    ptr = head->next;
    delete head;
    head = ptr;
  }
}

void printList(ListNode* head) {
  ListNode* ptr = head;
  while (ptr != nullptr) {
    if (ptr != head) {
      printf(" -> ");
    }
    printf("%d", ptr->val);
    ptr = ptr->next;
  }
  printf("\n");
}

// Merge sort
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while ((slow != nullptr) && (fast != nullptr)) {
      prev = slow;
      slow = slow->next;
      fast = (fast->next != nullptr ? fast->next->next : nullptr);
    }

    prev->next = nullptr;
    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);
    return mergeList(left, right);
  }

 private:
  ListNode* mergeList(ListNode* a, ListNode* b) {
    ListNode dummy;
    ListNode* ptr = &dummy;
    while (a != nullptr && b != nullptr) {
      if (a->val < b->val) {
        ptr->next = a;
        a = a->next;
        ptr = ptr->next;
      } else {
        ptr->next = b;
        b = b->next;
        ptr = ptr->next;
      }
    }

    if (a != nullptr) {
      ptr->next = a;
    } else if (b != nullptr) {
      ptr->next = b;
    }

    return dummy.next;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 5, 3, 4, 2, 0};
  if (argc > 2) {
    nums.clear();
    for (int i = 1; i < argc; i++) {
      nums.push_back(atoi(argv[i]));
    }
  }

  ListNode* head = createList(nums);
  printList(head);
  head = Solution().sortList(head);
  printList(head);
  deleteList(head);

  return 0;
}
