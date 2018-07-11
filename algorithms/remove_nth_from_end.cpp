/*
 * =====================================================================================
 *
 *       Filename:  remove_nth_from_end.cpp
 *
 *    Description:  Remove Nth Node From End of List: Given a linked list, remove the 
 *                  n-th node from the end of list and return its head.
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

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode fake_node(0);
        ListNode* fake_head = &fake_node;
        fake_head->next = head;

        ListNode** ptr = NULL;
        getNthFromEnd(&fake_head, n, &ptr);
        if (ptr == NULL || ptr == &fake_head)
        {
            return NULL;
        }

        *ptr = (*ptr)->next;
        return fake_head->next;
    }

private:
    int getNthFromEnd(ListNode** head, int n, ListNode*** ptr)
    {
        if (*head == NULL)
        {
            return 0;
        }

        int idx = 1 + getNthFromEnd(&((*head)->next), n, ptr);
        if (idx == n)
        {
            *ptr = head;
        }

        return idx;
    }
};

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
