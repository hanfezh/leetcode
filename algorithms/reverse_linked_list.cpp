/*
 * =====================================================================================
 *
 *       Filename:  reverse_linked_list.cpp
 *
 *    Description:  206. Reverse Linked List.
 *
 *        Version:  1.0
 *        Created:  04/11/19 03:11:07
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

// Iterative
class Solution1
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode fake(0);
        ListNode* ptr = head;
        ListNode* tmp = NULL;
        while (ptr != NULL)
        {
            tmp = ptr->next;
            ptr->next = fake.next;
            fake.next = ptr;
            ptr = tmp;
        }

        return fake.next;
    }
};

// Recursive
class Solution2
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* tail = NULL;
        return reverseList(head, &tail);
    }

private:
    ListNode* reverseList(ListNode* head, ListNode** tail)
    {
        if (head == NULL ||  head->next == NULL)
        {
            *tail = head;
            return head;
        }

        ListNode* ptr = reverseList(head->next, tail);
        (*tail)->next = head;
        head->next = NULL;
        *tail = head;
        return ptr;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    ListNode head(0);
    auto* reverse = Solution().reverseList(&head);
    return 0;
}
