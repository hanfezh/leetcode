// 242. Valid Anagram: https://leetcode.com/problems/valid-anagram
// Author: xianfeng.zhu@gmail.com

#include <assert.h>
#include <stdio.h>
#include <string>
#include <vector>

class Solution
{
public:
    bool isAnagram(const std::string& s, const std::string& t)
    {
        const int size = 'z' - 'a' + 1;
        std::vector<int> counts(size, 0);
        for (const auto chr: s)
        {
            counts[chr - 'a'] += 1;
        }

        for (const auto chr: t)
        {
            if (counts[chr - 'a'] == 0)
            {
                return false;
            }
            counts[chr - 'a'] -= 1;
        }

        for (const auto val: counts)
        {
            if (val > 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    std::string s = "anagram";
    std::string t = "nagaram";
    bool is_anagram = Solution().isAnagram(s, t);
    assert(is_anagram == true);
    return 0;
}
