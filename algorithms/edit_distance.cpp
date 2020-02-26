// 72. Edit Distance: https://leetcode.com/problems/edit-distance
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    int minDistance(const string& word1, const string& word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[m][n];
    }
};

int main(int argc, char* argv[])
{
    string word1 = "horse";
    string word2 = "ros";
    if (argc > 2)
    {
        word1 = argv[1];
        word2 = argv[2];
    }
    int steps = Solution().minDistance(word1, word2);
    printf("Input: word1 = %s, word2 = %s\n", word1.c_str(), word2.c_str());
    printf("Output: %d\n", steps);
    return 0;
}
