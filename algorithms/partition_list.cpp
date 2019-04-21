/*
 * =====================================================================================
 *
 *       Filename:  partition_list.cpp
 *
 *    Description:  86. Partition List. Given a linked list and a value x, partition it 
 *                  such that all nodes less than x come before nodes greater than or 
 *                  equal to x. You should preserve the original relative order of the 
 *                  nodes in each of the two partitions.
 *
 *        Version:  1.0
 *        Created:  04/21/19 14:45:04
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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode* p1 = &dummy1;
        ListNode* p2 = &dummy2;

        while (head != NULL)
        {
            if (head->val < x)
            {
                p1->next = head;
                p1 = p1->next;
            }
            else
            {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }

        p2->next = NULL;
        p1->next = dummy2.next;

        return dummy1.next;

    }
};

int main(int argc, char* argv[])
{
    ListNode* head = NULL;
    int x = 3;
    head = Solution().partition(head, x);
    return 0;
}
