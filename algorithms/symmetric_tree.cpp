/*
 * =====================================================================================
 *
 *       Filename:  symmetric_tree.cpp
 *
 *    Description:  Symmetric Tree. Given a binary tree, check whether it is a mirror of 
 *                  itself (ie, symmetric around its center).
 *
 *        Version:  1.0
 *        Created:  02/20/19 11:35:03
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
    bool isSymmetric(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }

        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode* a, TreeNode* b)
    {
        if (a == NULL && b == NULL)
        {
            return true;
        }
        else if (a == NULL || b == NULL)
        {
            return false;
        }

        if (a->val != b->val)
        {
            return false;
        }

        return (isSymmetric(a->left, b->right) && isSymmetric(a->right, b->left));
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto is_symmetric = Solution().isSymmetric(root);
    printf("Is symmetric? %s\n", is_symmetric ? "true" : "false");

    return 0;
}
