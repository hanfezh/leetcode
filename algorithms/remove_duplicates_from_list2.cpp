/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_list2.cpp
 *
 *    Description:  Remove Duplicates from Sorted List II
 *
 *        Version:  1.0
 *        Created:  02/22/19 04:43:02
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode fake(0);
        ListNode* last = &fake;
        ListNode* prev = head;
        ListNode* curr = (prev != NULL ? prev->next : NULL);
        bool is_dup = false;

        while (curr != NULL)
        {
            if (curr->val == prev->val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                is_dup = true;
                continue;
            }

            // curr->val != prev->val
            if (is_dup)
            {
                delete prev;
                prev = curr;
                curr = curr->next;
                is_dup = false;
            }
            else
            {
                last->next = prev;
                last = prev;
                last->next = NULL;
                prev = curr;
                curr = prev->next;
            }
        }

        if (!is_dup && prev != NULL)
        {
            last->next = prev;
        }

        return fake.next;
    }
};

int main(int argc, char* argv[])
{
    ListNode* root = NULL;
    root = Solution().deleteDuplicates(root);

    return 0;
}
