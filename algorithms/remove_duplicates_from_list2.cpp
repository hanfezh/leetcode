/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_list2.cpp
 *
 *    Description:  Remove Duplicates from Sorted List II
 *
 *        Version:  1.0
 *        Created:  02/22/19 04:43:02
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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Two pointers
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* p = &dummy;
    ListNode* left = p->next;
    ListNode* right = nullptr;
    bool duplicate = false;
    while (left != nullptr) {
      right = left->next;
      if (right != nullptr && left->val == right->val) {
        left->next = right->next;
        duplicate = true;
      } else if (duplicate) {
        p->next = left->next;
        left = left->next;
        duplicate = false;
      } else {
        p = p->next;
        left = left->next;
      }
    }
    return dummy.next;
  }
};

int main(int argc, char* argv[]) {
  ListNode* root = NULL;
  root = Solution().deleteDuplicates(root);

  return 0;
}
