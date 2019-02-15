/*
 * =====================================================================================
 *
 *       Filename:  rotate_list.cpp
 *
 *    Description:  Rotate List. Given a linked list, rotate the list to the right by k 
 *                  places, where k is non-negative.
 *
 *        Version:  1.0
 *        Created:  02/15/19 07:43:35
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        int len = 0;
        ListNode* prev;
        ListNode* node = head;
        while (node != NULL)
        {
            len += 1;
            prev = node;
            node = node->next;
        }

        if (len < 1)
        {
            // Empty list
            return head;
        }

        k %= len;
        int pos = len - k;
        int idx = 0;
        prev->next = head;
        node = head;
        while (idx < pos)
        {
            idx += 1;
            prev = node;
            node = node->next;
        }

        prev->next = NULL;
        return node;
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
    head = Solution().rotateRight(head, 2);
    printList(head);
    deleteList(head);

    return 0;
}
