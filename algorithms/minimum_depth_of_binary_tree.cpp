// =====================================================================================
//
//       Filename:  minimum_depth_of_binary_tree.cpp
//
//    Description:  111. Minimum Depth of Binary Tree.
//
//        Version:  1.0
//        Created:  08/13/2019 11:25:21 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <algorithm>

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
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 || right == 0)
        {
            return (left + right + 1);
        }
        return (std::min(left, right) + 1);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    int depth = Solution().minDepth(root);
    printf("Minimum depath: %d\n", depth);
    return 0;
}
