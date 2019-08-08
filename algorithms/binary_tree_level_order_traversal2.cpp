// =====================================================================================
//
//       Filename:  binary_tree_level_order_traversal2.cpp
//
//    Description:  107. Binary Tree Level Order Traversal II. Given a binary tree, 
//                  return the bottom-up level order traversal of its nodes' values. 
//                  (ie, from left to right, level by level from leaf to root).
//
//        Version:  1.0
//        Created:  08/08/2019 02:34:52 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfengzhu@tencent.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> values;
        levelOrderTop(root, 0, &values);
        std::reverse(values.begin(), values.end());
        return values;
    }

private:
    void levelOrderTop(TreeNode* node, int height, vector<vector<int>>* values)
    {
        if (node == nullptr)
        {
            return;
        }
        if (values->size() == height)
        {
            values->push_back(vector<int>());
        }

        int index = height;
        values->at(index).push_back(node->val);
        levelOrderTop(node->left, height + 1, values);
        levelOrderTop(node->right, height + 1, values);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    auto values = Solution().levelOrderBottom(root);
    printf("Values's size %ld\n", values.size());
    return 0;
}
