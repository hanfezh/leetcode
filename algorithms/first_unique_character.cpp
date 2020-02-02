// 387. First Unique Character in a String.
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <string>
#include <vector>

class Solution
{
public:
    int firstUniqChar(const std::string& s)
    {
        const int size = 'z' - 'a' + 1;
        std::vector<int> counts(size, 0);
        for (const auto chr: s)
        {
            counts[chr - 'a'] += 1;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (counts[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    std::string s = "loveleetcode";
    int idx = Solution().firstUniqChar(s);
    printf("First unique character in `%s`: %d\n", s.c_str(), idx);
    return 0;
}
