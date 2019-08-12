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

class Solution1
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

class Solution2
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        auto* ptr = head;
        int size = getLinkListSize(ptr);
        return sortedListToBST(&ptr, 0, size - 1);
    }

private:
    int getLinkListSize(ListNode* node)
    {
        int size = 0;
        while (node != nullptr)
        {
            node = node->next;
            size += 1;
        }
        return size;
    }

    TreeNode* sortedListToBST(ListNode** node, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        // Traverse left hand size
        int mid = (start + end) / 2;
        auto* left = sortedListToBST(node, start, mid - 1);

        // Create root
        auto* root = new TreeNode((*node)->val);
        root->left = left;

        // Move to next node
        *node = (*node)->next;

        // Traverse right hand side
        root->right = sortedListToBST(node, mid + 1, end);
        return root;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    ListNode* head = nullptr;
    auto* root = Solution().sortedListToBST(head);
    printf("root = %p\n", root);
    return 0;
}
