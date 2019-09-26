// =====================================================================================
//
//       Filename:  single_number2.cpp
//
//    Description:  137. Single Number II. Given a non-empty array of integers, every 
//                  element appears three times except for one, which appears exactly 
//                  once. Find that single one.
//
//        Version:  1.0
//        Created:  08/31/2019 10:47:47 AM
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

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        // a a a b
        // 1 1 1 1 -> (1 + 1 + 1 + 1) % 3 = 1
        // 1 1 1 0 -> (1 + 1 + 1 + 0) % 3 = 0
        // 0 0 0 1 -> (0 + 0 + 0 + 1) % 3 = 1
        // 0 0 0 0 -> (0 + 0 + 0 + 0) % 3 = 0
        int single = 0;

        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (auto n: nums)
            {
                sum += (n >> i) & 0x1;
            }

            single |= (sum % 3) << i;
        }

        return single;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    int single = Solution().singleNumber(nums);
    printf("The single number: %d\n", single);
    return 0;
}
