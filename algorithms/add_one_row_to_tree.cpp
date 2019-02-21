/*
 * =====================================================================================
 *
 *       Filename:  add_one_row_to_tree.cpp
 *
 *    Description:  Add One Row to Tree. Given the root of a binary tree, then value v 
 *                  and depth d, you need to add a row of nodes with value v at the 
 *                  given depth d. The root node is at depth 1.
 *
 *        Version:  1.0
 *        Created:  02/21/19 05:02:51
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
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if (d < 1)
        {
            return root;
        }
        else if (d == 1)
        {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }

        innerAddRow(root, v, d - 1);
        return root;
    }

private:
    void innerAddRow(TreeNode* node, int v, int d)
    {
        if (node == NULL || d < 1)
        {
            return;
        }
        if (d == 1)
        {
            TreeNode* l = new TreeNode(v);
            TreeNode* r = new TreeNode(v);
            l->left = node->left;
            r->right = node->right;
            node->left = l;
            node->right = r;
            return;
        }

        innerAddRow(node->left, v, d - 1);
        innerAddRow(node->right, v, d - 1);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    root = Solution().addOneRow(root, 1, 2);
    return 0;
}
