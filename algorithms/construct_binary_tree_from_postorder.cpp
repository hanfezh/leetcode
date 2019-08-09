// =====================================================================================
//
//       Filename:  construct_binary_tree_from_postorder.cpp
//
//    Description:  106. Construct Binary Tree from Inorder and Postorder Traversal.
//
//        Version:  1.0
//        Created:  08/09/2019 05:43:23 PM
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.size() != postorder.size())
        {
            return nullptr;
        }

        return buildTree(inorder, postorder, 0, 0, postorder.size());
    }

private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, 
                        int in_idx, int post_idx, int size)
    {
        if (size <= 0)
        {
            return nullptr;
        }

        int i = 0;
        for (i = in_idx; i < (in_idx + size); i++)
        {
            if (inorder[i] == postorder[post_idx + size - 1])
            {
                break;
            }
        }

        if (i >= (in_idx + size))
        {
            return nullptr;
        }

        auto* root = new TreeNode(postorder[post_idx + size - 1]);
        int left_size = i - in_idx;
        int right_size = size - left_size - 1;
        root->left = buildTree(inorder, postorder, in_idx, post_idx, left_size);
        root->right = buildTree(inorder, postorder, i + 1, post_idx + left_size, right_size);

        return root;
    }
};

int main(int argc, char* argv[])
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    auto* root = Solution().buildTree(inorder, postorder);
    printf("root != nullptr -> %s\n", ((root != nullptr) ? "true" : "false"));
    return 0;
}
