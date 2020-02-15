// 412. Fizz Buzz: https://leetcode.com/problems/fizz-buzz
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> nums;

        for (int i = 1; i <= n; i++)
        {
            string str;
            if ((i % 3) == 0)
            {
                str = "Fizz";
            }
            if ((i % 5) == 0)
            {
                str += "Buzz";
            }
            if (str.empty())
            {
                str = std::to_string(i);
            }
            nums.push_back(str);
        }

        return nums;
    }
};

int main(int argc, char* argv[])
{
    int n = 15;
    auto nums = Solution().fizzBuzz(n);
    for (const auto& str: nums)
    {
        printf("%s\n", str.c_str());
    }
    return 0;
}
