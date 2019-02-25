/*
 * =====================================================================================
 *
 *       Filename:  remove_linked_list_elements.cpp
 *
 *    Description:  Remove Linked List Elements. Remove all elements from a linked list 
 *                  of integers that have value val.
 *
 *        Version:  1.0
 *        Created:  02/25/19 03:21:52
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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode fake(0);
        ListNode* last = &fake;
        while (head != NULL)
        {
            if (head->val == val)
            {
                ListNode* ptr = head;
                head = head->next;
                delete ptr;
            }
            else
            {
                last->next = head;
                last = head;
                head = head->next;
                last->next = NULL;
            }
        }

        return fake.next;
    }
};

int main(int argc, char* argv[])
{
    ListNode* head = NULL;
    head = Solution().removeElements(head, 10);

    return 0;
}
