/*
 * =====================================================================================
 *
 *       Filename:  remove_nth_from_end.cpp
 *
 *    Description:  19. Remove Nth Node From End of List: Given a linked list, remove 
 *                  the n-th node from the end of list and return its head.
 *
 *        Version:  1.0
 *        Created:  07/11/18 01:29:52
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
#include <vector>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(const std::vector<int>& nums)
{
    ListNode* head = NULL;
    ListNode* p = NULL;
    ListNode* n = NULL;

    for (size_t i = 0; i < nums.size(); i++)
    {
        n = new ListNode(nums[i]);
        if (i == 0)
        {
            head = n;
        }
        else
        {
            p->next = n;
        }
        p = n;
    }

    return head;
}

void deleteList(ListNode* head)
{
    ListNode* ptr = NULL;
    while (head != NULL)
    {
        ptr = head->next;
        delete head;
        head = ptr;
    }
}

void printList(ListNode* head)
{
    ListNode* ptr = head;
    while (ptr != NULL)
    {
        if (ptr != head)
        {
            printf(" -> ");
        }
        printf("%d", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

// Iterative
class Solution1
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* p = head;
        while (p != NULL)
        {
            p = p->next;
            n--;
        }

        n = std::abs(n);
        p = &dummy;
        while (n > 0)
        {
            p = p->next;
            n--;
        }

        ListNode* q = p->next;
        p->next = q->next;

        delete q;
        return dummy.next;
    }
};

// Two pointers
class Solution2
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* p = &dummy;
        ListNode* q = &dummy;
        while (n >= 0)
        {
            n--;
            q = q->next;
        }
        while (q != NULL)
        {
            p = p->next;
            q = q->next;
        }

        q = p->next;
        p->next = q->next;

        delete q;
        return dummy.next;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    if (argc > 2)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    ListNode* head = createList(nums);
    printList(head);
    head = Solution().removeNthFromEnd(head, 2);
    printList(head);
    deleteList(head);

    return 0;
}
