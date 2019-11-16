/*
 * =====================================================================================
 *
 *       Filename:  symmetric_tree.cpp
 *
 *    Description:  101. Symmetric Tree. Given a binary tree, check whether it is a 
 *                  mirror of itself (ie, symmetric around its center).
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
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive
class Solution1
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
        else if (a->val != b->val)
        {
            return false;
        }

        return (isSymmetric(a->left, b->right) && isSymmetric(a->right, b->left));
    }
};

// Iterative
class Solution2
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }

        std::queue<TreeNode*> nodes;
        nodes.push(root->left);
        nodes.push(root->right);
        while (!nodes.empty())
        {
            auto* a = nodes.front();
            nodes.pop();
            auto* b = nodes.front();
            nodes.pop();
            if (a == NULL && b == NULL)
            {
                continue;
            }
            else if (a == NULL || b == NULL || a->val != b->val)
            {
                return false;
            }

            // Push subnodes
            nodes.push(a->left);
            nodes.push(b->right);
            nodes.push(a->right);
            nodes.push(b->left);
        }

        return true;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto is_symmetric = Solution().isSymmetric(root);
    printf("Is symmetric? %s\n", is_symmetric ? "true" : "false");

    return 0;
}
