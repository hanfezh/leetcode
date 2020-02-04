// 208. Implement Trie: https://leetcode.com/problems/implement-trie-prefix-tree
// Author: xianfeng.zhu@gmail.com

#include <assert.h>
#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Use std::string
class Trie1
{
public:
    /** Initialize your data structure here. */
    Trie1()
    {
        value_ = " ";
    }
    
    /** Inserts a word into the trie. */
    void insert(const string& word)
    {
        value_ += word + " ";
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word)
    {
        return (value_.find(" " + word + " ") != string::npos);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix)
    {
        return (value_.find(" " + prefix) != string::npos);
    }

private:
    string value_;
};

// Implement prefix tree
class Trie2
{
    struct Node
    {
        // Children's indices
        int indices[26] = {};
        bool is_end = false;
    };

public:
    /** Initialize your data structure here. */
    Trie2(): nodes_(1, Node())
    {
    }
    
    /** Inserts a word into the trie. */
    void insert(const string& word)
    {
        int idx = 0;
        for (const auto chr: word)
        {
            if (nodes_[idx].indices[chr - 'a'] == 0)
            {
                // Append new node to the end
                nodes_.emplace_back();
                nodes_[idx].indices[chr - 'a'] = nodes_.size() - 1;
                idx = nodes_.size() - 1;
            }
            else
            {
                idx = nodes_[idx].indices[chr - 'a'];
            }
        }
        nodes_[idx].is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word)
    {
        const auto* node = find(word);
        return (node != nullptr && node->is_end);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix)
    {
        const auto* node = find(prefix);
        return (node != nullptr);
    }

private:
    const Node* find(const string& word)
    {
        int idx = 0;
        for (const auto chr: word)
        {
            idx = nodes_[idx].indices[chr - 'a'];
            if (idx == 0)
            {
                return nullptr;
            }
        }

        return &nodes_[idx];
    }

private:
    vector<Node> nodes_;
};

using Trie = Trie2;

int main(int argc, char* argv[])
{
    Trie trie;
    trie.insert("apple");
    assert(trie.search("apple") == true);
    assert(trie.search("app") == false);
    assert(trie.startsWith("app") == true);
    trie.insert("app");
    assert(trie.search("app") == true);
    return 0;
}
