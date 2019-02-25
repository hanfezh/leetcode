/*
 * =====================================================================================
 *
 *       Filename:  delete_node_in_linked_list.cpp
 *
 *    Description:  Delete Node in a Linked List.
 *
 *        Version:  1.0
 *        Created:  02/22/19 09:26:15
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        if (node == NULL || node->next == NULL)
        {
            // Except the tail
            return;
        }

        ListNode* ptr = node->next;
        node->val = ptr->val;
        node->next = ptr->next;
        delete ptr;
    }
};

int main(int argc, char* argv[])
{
    ListNode* head = NULL;
    Solution().deleteNode(head);

    return 0;
}
