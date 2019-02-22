/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_list.cpp
 *
 *    Description:  Remove Duplicates from Sorted List.
 *
 *        Version:  1.0
 *        Created:  02/21/19 13:06:44
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
        ListNode* prev = head;
        ListNode* curr = (prev != NULL ? prev->next : NULL);

        while (curr != NULL)
        {
            if (curr->val == prev->val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

int main(int argc, char* argv[])
{
    ListNode* root = NULL;
    root = Solution().deleteDuplicates(root);

    return 0;
}
