/*
 * =====================================================================================
 *
 *       Filename:  validate_binary_search_tree.cpp
 *
 *    Description:  Validate Binary Search Tree. Given a binary tree, determine if it is 
 *                  a valid binary search tree (BST).
 *
 *        Version:  1.0
 *        Created:  02/28/19 01:50:49
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
    bool isValidBST(TreeNode* root)
    {
        return doValidate(root, NULL, NULL);
    }

private:
    bool doValidate(TreeNode* node, TreeNode* min, TreeNode* max)
    {
        if (node == NULL)
        {
            return true;
        }
        if ((min != NULL && node->val <= min->val) ||
            (max != NULL && node->val >= max->val))
        {
            return false;
        }
        return (doValidate(node->left, min, node) && doValidate(node->right, node, max));
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto valid = Solution().isValidBST(root);
    printf("Is a valid binary search tree? %s\n", (valid ? "Yes" : "No"));
    return 0;
}
