// =====================================================================================
//
//       Filename:  construct_binary_tree_from_order.cpp
//
//    Description:  105. Construct Binary Tree from Preorder and Inorder Traversal.
//
//        Version:  1.0
//        Created:  08/07/2019 08:48:02 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <vector>

using std::vector;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() != inorder.size() || preorder.size() < 1)
        {
            return nullptr;
        }

        return buildTree(preorder, inorder, 0, 0, preorder.size());
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, 
                        int pre_start, int in_start, int sub_size)
    {
        if (sub_size <= 0)
        {
            return nullptr;
        }

        int i = 0;
        for (i = in_start; i < (in_start + sub_size); i++)
        {
            if (preorder[pre_start] == inorder[i])
            {
                // Found
                break;
            }
        }

        if (i >= (in_start + sub_size))
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_start]);
        root->left = buildTree(preorder, inorder, pre_start + 1, in_start, i - in_start);
        root->right = buildTree(preorder, inorder, pre_start + (i - in_start + 1), i + 1, sub_size - (i - in_start + 1));

        return root;
    }
};

int main(int argc, char* argv[])
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    auto* root = Solution().buildTree(preorder, inorder);
    printf("root != nullptr -> %s\n", ((root != nullptr) ? "true" : "false"));
    return 0;
}
