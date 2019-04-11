/*
 * =====================================================================================
 *
 *       Filename:  sort_list.cpp
 *
 *    Description:  148. Sort List.
 *                  Sort a linked list in O(nlogn) time using constant space complexity.
 *
 *        Version:  1.0
 *        Created:  04/11/19 11:24:07
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
    ListNode* sortList(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        while ((slow != NULL) && (fast != NULL))
        {
            prev = slow;
            slow = slow->next;
            fast = (fast->next != NULL ? fast->next->next : NULL);
        }

        prev->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return mergeList(left, right);
    }

private:
    ListNode* mergeList(ListNode* a, ListNode* b)
    {
        ListNode fake(0);
        ListNode* ptr = &fake;
        while (a != NULL && b != NULL)
        {
            if (a->val < b->val)
            {
                ptr->next = a;
                a = a->next;
                ptr = ptr->next;
                ptr->next = NULL;
            }
            else
            {
                ptr->next = b;
                b = b->next;
                ptr = ptr->next;
                ptr->next = NULL;
            }
        }

        if (a != NULL)
        {
            ptr->next = a;
        }
        else if (b != NULL)
        {
            ptr->next = b;
        }

        return fake.next;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 5, 3, 4, 2, 0};
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
    head = Solution().sortList(head);
    printList(head);
    deleteList(head);

    return 0;
}
