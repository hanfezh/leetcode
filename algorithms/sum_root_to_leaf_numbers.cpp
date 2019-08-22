// =====================================================================================
//
//       Filename:  sum_root_to_leaf_numbers.cpp
//
//    Description:  129. Sum Root to Leaf Numbers.
//
//        Version:  1.0
//        Created:  08/22/2019 10:42:52 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
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
    int sumNumbers(TreeNode* root)
    {
        return sumNumbers(root, 0);
    }

private:
    int sumNumbers(TreeNode* node, int parent)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else if (node->left == nullptr && node->right == nullptr)
        {
            return parent * 10 + node->val;
        }

        parent = parent * 10 + node->val;
        int left = sumNumbers(node->left, parent);
        int right = sumNumbers(node->right, parent);

        return left + right;
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    int sum = Solution().sumNumbers(root);
    printf("Sum root to leaf numbers -> %d\n", sum);
    return 0;
}
