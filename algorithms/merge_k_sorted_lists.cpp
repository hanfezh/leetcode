/*
 * =====================================================================================
 *
 *       Filename:  merge_k_sorted_lists.cpp
 *
 *    Description:  23. Merge k Sorted Lists. Merge k sorted linked lists and return it 
 *                  as one sorted list. Analyze and describe its complexity.
 *
 *        Version:  1.0
 *        Created:  04/16/19 01:42:07
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

class Solution
{
public:
    ListNode* mergeKLists(const std::vector<ListNode*>& lists)
    {
        if (lists.empty())
        {
            return NULL;
        }

        ListNode* first = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            first = mergeList(first, lists[i]);
        }

        return first;
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
    std::vector<ListNode*> lists;
    auto* sorted = Solution().mergeKLists(lists);
    return 0;
}
