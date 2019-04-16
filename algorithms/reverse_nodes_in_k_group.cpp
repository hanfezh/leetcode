/*
 * =====================================================================================
 *
 *       Filename:  reverse_nodes_in_k_group.cpp
 *
 *    Description:  25. Reverse Nodes in k-Group. Given a linked list, reverse the nodes 
 *                  of a linked list k at a time and return its modified list.
 *
 *        Version:  1.0
 *        Created:  04/16/19 12:50:00
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k < 2)
        {
            return head;
        }

        ListNode dummy(0);
        ListNode* first = &dummy;
        ListNode* last = &dummy;
        ListNode* ptr = head;
        ListNode* tmp = NULL;
        int i = 0;
        while (ptr != NULL)
        {
            i++;
            tmp = ptr->next;
            ptr->next = first->next;
            first->next = ptr;

            i %= k;
            if (i == 1)
            {
                // First node
                last = ptr;
            }
            else if (i == 0)
            {
                // Last node
                first = last;
            }

            ptr = tmp;
        }

        if (i > 0)
        {
            ptr = first->next;
            first->next = NULL;
            while (ptr != NULL)
            {
                tmp = ptr->next;
                ptr->next = first->next;
                first->next = ptr;
                ptr = tmp;
            }
        }

        return dummy.next;
    }
};

int main(int argc, char* argv[])
{
    ListNode head(0);
    auto* reverse = Solution().reverseKGroup(&head, 2);
    return 0;
}
