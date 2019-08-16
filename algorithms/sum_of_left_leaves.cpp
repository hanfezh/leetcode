// =====================================================================================
//
//       Filename:  sum_of_left_leaves.cpp
//
//    Description:  404. Sum of Left Leaves. 
//                  Find the sum of all left leaves in a given binary tree.
//
//        Version:  1.0
//        Created:  08/08/2019 10:35:59 AM
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
    int sumOfLeftLeaves(TreeNode* root)
    {
        int sum = 0;
        sumOfLeftLeaves(root, false, &sum);
        return sum;
    }

private:
    void sumOfLeftLeaves(TreeNode* node, bool is_left, int* sum)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->left == nullptr && node->right == nullptr && is_left)
        {
            // Current node is leaf
            *sum += node->val;
        }

        sumOfLeftLeaves(node->left, true, sum);
        sumOfLeftLeaves(node->right, false, sum);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    auto sum = Solution().sumOfLeftLeaves(root);
    printf("Sum of left leaves? %d\n", sum);
    return 0;
}
