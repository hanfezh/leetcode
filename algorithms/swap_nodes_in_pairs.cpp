/*
 * =====================================================================================
 *
 *       Filename:  swap_nodes_in_pairs.cpp
 *
 *    Description:  Swap Nodes in Pairs: Given a linked list, swap every two adjacent 
 *                  nodes and return its head.
 *
 *        Version:  1.0
 *        Created:  07/10/18 11:12:21
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
 
// Non-recursive
class Solution1
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode fake(0);
        fake.next = head;

        ListNode* p = &fake;
        ListNode* q = p->next;
        ListNode* r = q->next;

        while (r != NULL)
        {
            q->next = r->next;
            r->next = q;
            p->next = r;

            p = q;
            q = p->next;
            r = (q != NULL ? q->next : NULL);
        }

        return fake.next;
    }
};

// Recursive
class Solution2
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        auto* ptr = head->next;
        head->next = swapPairs(head->next->next);
        ptr->next = head;
        return ptr;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3};
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
    head = Solution().swapPairs(head);
    printList(head);
    deleteList(head);

    return 0;
}
