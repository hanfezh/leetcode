/*
 * =====================================================================================
 *
 *       Filename:  find_mode_in_binary_search_tree.cpp
 *
 *    Description:  Find Mode in Binary Search Tree.
 *
 *        Version:  1.0
 *        Created:  02/28/19 06:24:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <vector>
#include <unordered_map>

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
    std::vector<int> findMode(TreeNode* root)
    {
        std::unordered_map<int, int> counts;
        dfsTree(root, counts);

        std::vector<int> modes;
        int max = 0;
        for (const auto& item: counts)
        {
            if (item.second < max)
            {
                continue;
            }

            // item.second >= max
            if (item.second > max)
            {
                modes.clear();
                max = item.second;
            }
            modes.push_back(item.first);
        }

        return modes;
    }

private:
    void dfsTree(TreeNode* node, std::unordered_map<int, int>& counts)
    {
        if (node == NULL)
        {
            return;
        }

        auto ret_pair = counts.insert(std::make_pair(node->val, 1));
        if (!ret_pair.second)
        {
            ret_pair.first->second += 1;
        }

        dfsTree(node->left, counts);
        dfsTree(node->right, counts);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto modes = Solution().findMode(root);
    return 0;
}
