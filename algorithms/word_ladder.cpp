// =====================================================================================
//
//       Filename:  word_ladder.cpp
//
//    Description:  127. Word Ladder.
//
//        Version:  1.0
//        Created:  08/20/2019 04:48:30 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfengzhu@tencent.com
//   Organization:  Tencent Tech. Co., Ltd.
//
// =====================================================================================
#include <stdio.h>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int ladderLength(const string& begin_word, const string& end_word, vector<string>& word_list)
    {
        unordered_set<string> words(word_list.begin(), word_list.end());
        queue<string> bfs_queue;
        int ladders = 0;

        // Push first node
        bfs_queue.push(begin_word);

        // Breadth first search
        while (!bfs_queue.empty())
        {
            ladders++;
            int bfs_size = bfs_queue.size();
            while (bfs_size-- > 0)
            {
                auto node = bfs_queue.front();
                bfs_queue.pop();

                if (node == end_word)
                {
                    // Found and return
                    return ladders;
                }

                // Erase node from set, mark as visited
                words.erase(node);

                // Try to find all adjacent node
                for (int i = 0; i < node.size(); i++)
                {
                    // Keep original char
                    char c = node[i];

                    // Traverse letter a~z
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        node[i] = j;
                        if (words.count(node) > 0)
                        {
                            // Found adjacent node
                            bfs_queue.push(node);
                        }
                    }

                    // Recover orignal char
                    node[i] = c;
                }
            }
        }

        // Doesn't find
        return 0;
    }
};

int main(int argc, char* argv[])
{
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    int ladders = Solution().ladderLength("hit", "cog", word_list);
    printf("%d\n", ladders);
    return 0;
}
