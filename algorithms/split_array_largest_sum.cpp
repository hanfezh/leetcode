// =====================================================================================
//
//       Filename:  split_array_largest_sum.cpp
//
//    Description:  410. Split Array Largest Sum.
//
//        Version:  1.0
//        Created:  11/14/2019 12:54:33 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stdint.h>
#include <algorithm>
#include <vector>

using std::vector;

// Binary search
class Solution
{
public:
    int splitArray(vector<int>& nums, int m)
    {
        int64_t sum = 0;
        int max_num = 0;
        for (auto num: nums)
        {
            sum += num;
            max_num = std::max(max_num, num);
        }

        if (m == 1)
        {
            return sum;
        }
        if (m >= nums.size() - 1)
        {
            return max_num;
        }

        int64_t left = max_num;
        int64_t right = sum;
        while (left <= right)
        {
            int64_t middle = (left + right) / 2;
            if (isValid(nums, m, middle))
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return (int)left;
    }

private:
    bool isValid(vector<int>& nums, int m, int target)
    {
        int sum = 0;
        int count = 1;
        for (auto num: nums)
        {
            sum += num;
            if (sum > target)
            {
                sum = num;
                count++;
                if (count > m)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;
    int largest = Solution().splitArray(nums, m);
    printf("The minimize the largest sum is %d\n", largest);
    return 0;
}
