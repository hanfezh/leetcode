// 297. Serialize and Deserialize Binary Tree
// Author: xianfeng.zhu@gmail.com

#include <string>

using std::string;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive, DFS
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (root == nullptr)
        {
            // Use '*' represent nullptr
            return string("*");
        }

        string data = std::to_string(root->val);
        data += " " + serialize(root->left);
        data += " " + serialize(root->right);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data)
    {
        int start = 0;
        return deserialize(data, start);
    }

private:
    TreeNode* deserialize(const string& data, int& start)
    {
        auto idx = data.find(' ', start);
        string sub = data.substr(start, (idx != string::npos ? (idx - start) : string::npos));
        if (sub == "*")
        {
            start = idx + 1;
            return nullptr;
        }

        start = idx + 1;
        TreeNode* node = new TreeNode(std::stoi(sub));
        node->left = deserialize(data, start);
        node->right = deserialize(data, start);
        return node;
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    Codec codec;
    auto* tree = codec.deserialize(codec.serialize(root));
    return 0;
}
