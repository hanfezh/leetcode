// =====================================================================================
//
//       Filename:  flatten_binary_tree_to_linked_list.cpp
//
//    Description:  114. Flatten Binary Tree to Linked List.
//
//        Version:  1.0
//        Created:  08/13/2019 02:52:04 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfengzhu@tencent.com
//   Organization:  Tencent Tech. Co., Ltd.
//
// =====================================================================================
#include <stdio.h>

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
    void flatten(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        if (root->left != nullptr)
        {
            auto* last = root->left;
            while (last->right != 0)
            {
                last = last->right;
            }

            last->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    Solution().flatten(root);
    return 0;
}
