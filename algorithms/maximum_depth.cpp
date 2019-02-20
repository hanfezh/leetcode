/*
 * =====================================================================================
 *
 *       Filename:  maximum_depth.cpp
 *
 *    Description:  Maximum Depth of Binary Tree
 *
 *        Version:  1.0
 *        Created:  02/20/19 13:04:35
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
    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int a = maxDepth(root->left) + 1;
        int b = maxDepth(root->right) + 1;

        return (a > b ? a : b);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto depth = Solution().maxDepth(root);
    printf("Maximum depth of binary tree? %d\n", depth);

    return 0;
}
