/*
 * =====================================================================================
 *
 *       Filename:  univalued_binary_tree.cpp
 *
 *    Description:  Univalued Binary Tree. A binary tree is univalued if every node in 
 *                  the tree has the same value. Return true if and only if the given 
 *                  tree is univalued.
 *
 *        Version:  1.0
 *        Created:  02/28/19 07:04:39
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
    bool isUnivalTree(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        return isUnivalTree(root, root->val);
    }

private:
    bool isUnivalTree(TreeNode* node, int val)
    {
        if (node == NULL)
        {
            return true;
        }
        if (node->val != val)
        {
            return false;
        }

        return isUnivalTree(node->left, node->val) && isUnivalTree(node->right, node->val);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto is_unival = Solution().isUnivalTree(root);
    printf("Is univaled binary tree? %s\n", (is_unival ? "Yes" : "No"));
    return 0;
}
