/*
 * =====================================================================================
 *
 *       Filename:  linked_list_cycle2.cpp
 *
 *    Description:  142. Linked List Cycle II. Given a linked list, return the node
 *                  where the cycle begins. If there is no cycle, return null.
 *
 *        Version:  1.0
 *        Created:  02/19/19 09:41:50
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
#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(const std::vector<int>& nums) {
  ListNode* head = NULL;
  ListNode* p = NULL;
  ListNode* n = NULL;

  for (size_t i = 0; i < nums.size(); i++) {
    n = new ListNode(nums[i]);
    if (i == 0) {
      head = n;
    } else {
      p->next = n;
    }
    p = n;
  }

  return head;
}

void deleteList(ListNode* head) {
  ListNode* ptr = NULL;
  while (head != NULL) {
    ptr = head->next;
    delete head;
    head = ptr;
  }
}

void printList(ListNode* head) {
  ListNode* ptr = head;
  while (ptr != NULL) {
    if (ptr != head) {
      printf(" -> ");
    }
    printf("%d", ptr->val);
    ptr = ptr->next;
  }
  printf("\n");
}

// Two pointers
class Solution1 {
 public:
  /**
   * x: head -> cycle start point
   * y: cycle length
   * k: meet point
   * slow path: t = x + ny + k
   * fast path: 2t = x + my + k
   * -> 2 * (x + ny + k) = x + my + k
   * -> x + k = (m - 2n) * y
   */
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // First meet
    while (slow != NULL && fast != NULL) {
      slow = slow->next;
      fast = (fast->next != NULL ? fast->next->next : NULL);

      if (slow == fast) {
        // Found cycle
        break;
      }
    }

    if (fast == NULL) {
      // No cycle
      return NULL;
    }

    // Second meet
    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }

    return fast;
  }
};

// Hash table
class Solution2 {
 public:
  ListNode* detectCycle(ListNode* head) {
    std::unordered_set<ListNode*> nodes;
    ListNode* ptr = head;
    while (ptr != nullptr) {
      auto ret_pair = nodes.insert(ptr);
      if (not ret_pair.second) {
        // Already exists, found cycle start node
        return ptr;
      }
      ptr = ptr->next;
    }
    return nullptr;
  }
};

using Solution = Solution1;

int main(int argc, char* argv[])
{
  std::vector<int> nums = {1, 2, 3, 4, 5};
  if (argc > 2) {
    nums.clear();
    for (int i = 1; i < argc; i++) {
      nums.push_back(atoi(argv[i]));
    }
  }

  ListNode* head = createList(nums);
  printList(head);
  auto* cycle = Solution().detectCycle(head);
  printf("Has cycle? %s\n", (cycle != NULL ? "Yes" : "No"));
  deleteList(head);

  return 0;
}
