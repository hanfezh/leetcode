/*
 * =====================================================================================
 *
 *       Filename:  same_tree.cpp
 *
 *    Description:  Same Tree. Given two binary trees, write a function to check if they 
 *                  are the same or not.
 *
 *        Version:  1.0
 *        Created:  02/21/19 01:46:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if (p == NULL || q == NULL)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main(int argc, char* argv[])
{
    TreeNode* a = NULL;
    TreeNode* b = NULL;
    auto is_same = Solution().isSameTree(a, b);
    printf("Same tree? %s\n", (is_same ? "Yes" : "No"));

    return 0;
}
