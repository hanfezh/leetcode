/*
 * =====================================================================================
 *
 *       Filename:  balanced_binary_tree.cpp
 *
 *    Description:  110. Balanced Binary Tree.
 *                  Given a binary tree, determine if it is height-balanced.
 *
 *        Version:  1.0
 *        Created:  04/12/19 12:42:30
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
#include <algorithm>

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
    bool isBalanced(TreeNode* root)
    {
        return (checkHeight(root) != -1);
    }

private:
    int checkHeight(TreeNode* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int left = checkHeight(node->left);
        if (left == -1)
        {
            // Left subtree isn't balanced
            return -1;
        }

        int right = checkHeight(node->right);
        if (right == -1)
        {
            // Right subtree isn't balanced
            return -1;
        }

        if (std::abs(left - right) > 1)
        {
            // Current tree isn't balanced
            return -1;
        }

        // Return current tree's height
        return std::max(left, right) + 1;
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto balanced = Solution().isBalanced(root);
    printf("Is balanced binary tree? %s\n", (balanced ? "Yes" : "No"));
    return 0;
}
