// 234. Palindrome Linked List
// Author: xianfengzhu@gmail.com

#include <stdio.h>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Recursive
class Solution1 {
 public:
  bool isPalindrome(ListNode* head) { return isPalindrome(&head, head); }

 private:
  bool isPalindrome(ListNode** head, ListNode* tail) {
    if (tail == nullptr) {
      return true;
    }

    bool is_pal = isPalindrome(head, tail->next);
    if (!is_pal || (*head)->val != tail->val) {
      return false;
    }

    *head = (*head)->next;
    return true;
  }
};

// Two pointers, reverse first half of linked list
class Solution2 {
 public:
  bool isPalindrome(ListNode* head) {
    ListNode dummy(0);
    ListNode* ptr = &dummy;
    ListNode* tmp = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (slow != nullptr && fast != nullptr) {
      if (fast->next == nullptr) {
        slow = slow->next;
        break;
      }
      fast = fast->next->next;
      tmp = slow->next;
      slow->next = ptr->next;
      ptr->next = slow;
      slow = tmp;
    }

    ptr = dummy.next;
    while (slow != nullptr) {
      if (ptr->val != slow->val) {
        return false;
      }
      slow = slow->next;
      ptr = ptr->next;
    }
    return true;
  }
};

using Solution = Solution2;

int main(int argc, char* argv[]) {
  ListNode* head = nullptr;
  bool is_pal = Solution().isPalindrome(head);
  printf("Is palindrome? %s\n", (is_pal ? "Yes" : "No"));
  return 0;
}
