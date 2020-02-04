// 208. Implement Trie: https://leetcode.com/problems/implement-trie-prefix-tree
// Author: xianfeng.zhu@gmail.com

#include <assert.h>
#include <stdio.h>
#include <string>

using std::string;

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
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
