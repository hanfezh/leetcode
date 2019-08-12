// =====================================================================================
//
//       Filename:  convert_sorted_list_to_bst.cpp
//
//    Description:  109. Convert Sorted List to Binary Search Tree.
//
//        Version:  1.0
//        Created:  08/12/2019 10:29:23 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        return sortedListToBST(head, nullptr);
    }

private:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail)
    {
        if (head == tail)
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, tail);

        return root;
    }
};

int main(int argc, char* argv[])
{
    ListNode* head = nullptr;
    auto* root = Solution().sortedListToBST(head);
    printf("root = %p\n", root);
    return 0;
}
