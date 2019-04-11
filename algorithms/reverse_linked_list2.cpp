/*
 * =====================================================================================
 *
 *       Filename:  reverse_linked_list2.cpp
 *
 *    Description:  92. Reverse Linked List II.
 *
 *        Version:  1.0
 *        Created:  04/11/19 03:39:11
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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode fake(0);
        ListNode* first = &fake;
        ListNode* last = &fake;
        ListNode* ptr = head;
        ListNode* tmp = NULL;
        int i = 0;
        while (ptr != NULL)
        {
            i++;
            if (i >= m && i <= n)
            {
                // Reverse
                tmp = ptr->next;
                ptr->next = first->next;
                first->next = ptr;
                if (i == m)
                {
                    last = ptr;
                }
                ptr = tmp;
            }
            else
            {
                // Forward
                tmp = ptr->next;
                ptr->next = NULL;
                last->next = ptr;
                last = last->next;
                first = last;
                ptr = tmp;
            }
        }

        return fake.next;
    }
};

int main(int argc, char* argv[])
{
    ListNode head(0);
    auto* reverse = Solution().reverseBetween(&head, 0, 0);
    return 0;
}
