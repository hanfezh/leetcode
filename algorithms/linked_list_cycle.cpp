/*
 * =====================================================================================
 *
 *       Filename:  linked_list_cycle.cpp
 *
 *    Description:  Linked List Cycle. 
 *                  Given a linked list, determine if it has a cycle in it.
 *
 *        Version:  1.0
 *        Created:  02/19/19 02:07:23
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
    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = (head != NULL ? head->next : NULL);

        while (slow != NULL && fast != NULL)
        {
            if (slow == fast)
            {
                return true;
            }

            slow = slow->next;
            fast = (fast->next != NULL ? fast->next->next : NULL);
        }

        return false;
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
    auto has_cycle = Solution().hasCycle(head);
    printf("Has cycle? %c\n", (has_cycle ? 'Y' : 'N'));
    deleteList(head);

    return 0;
}
