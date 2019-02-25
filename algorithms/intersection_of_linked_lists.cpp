/*
 * =====================================================================================
 *
 *       Filename:  intersection_of_linked_lists.cpp
 *
 *    Description:  Intersection of Two Linked Lists. Write a program to find the node 
 *                  at which the intersection of two singly linked lists begins.
 *
 *        Version:  1.0
 *        Created:  02/25/19 03:50:57
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
    ListNode* getIntersectionNode(ListNode* a, ListNode* b)
    {
        int m = 0;
        int n = 0;

        auto* p = a;
        while (p != NULL)
        {
            m++;
            p = p->next;
        }

        p = b;
        while (p != NULL)
        {
            n++;
            p = p->next;
        }

        while (m > n)
        {
            a = a->next;
            m--;
        }
        while (n > m)
        {
            b = b->next;
            n--;
        }

        while (a != b)
        {
            a = a->next;
            b = b->next;
        }

        return a;
    }
};

int main(int argc, char* argv[])
{
    ListNode* a = NULL;
    ListNode* b = NULL;
    auto* node = Solution().getIntersectionNode(a, b);

    return 0;
}
