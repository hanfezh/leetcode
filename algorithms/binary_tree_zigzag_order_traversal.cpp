// =====================================================================================
//
//       Filename:  binary_tree_zigzag_order_traversal.cpp
//
//    Description:  103. Binary Tree Zigzag Level Order Traversal.
//
//        Version:  1.0
//        Created:  08/09/2019 07:53:48 PM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> values;
        zigzagLevelOrder(root, 0, &values);
        return values;
    }

private:
    void zigzagLevelOrder(TreeNode* node, int height, vector<vector<int>>* values)
    {
        if (node == nullptr)
        {
            return;
        }
        if (values->size() == height)
        {
            values->push_back(vector<int>());
        }

        if ((height & 0x01) == 0)
        {
            values->at(height).push_back(node->val);
        }
        else
        {
            values->at(height).insert(values->at(height).begin(), node->val);
        }

        zigzagLevelOrder(node->left, height + 1, values);
        zigzagLevelOrder(node->right, height + 1, values);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    auto values = Solution().zigzagLevelOrder(root);
    printf("Values's size %ld\n", values.size());
    return 0;
}
