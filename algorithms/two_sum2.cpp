/*
 * =====================================================================================
 *
 *       Filename:  two_sum2.cpp
 *
 *    Description:  Two Sum II - Input array is sorted.
 *
 *        Version:  1.0
 *        Created:  03/04/19 06:58:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target)
    {
        int low;
        int high;

        for (low = 0, high = numbers.size() - 1; (low < numbers.size() - 1) && (low < high); )
        {
            int left = target - numbers[high];
            if (left < numbers[low])
            {
                high--;
            }
            else if (left > numbers[low])
            {
                low++;
            }
            else
            {
                // left == numbers[low]
                return std::vector<int>({low + 1, high + 1});
            }
        }

        return std::vector<int>();
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> numbers = {2, 7, 11, 15};
    auto indices = Solution().twoSum(numbers, 9);
    if (!indices.empty())
    {
        printf("Found!");
        for (auto idx: indices)
        {
            printf(" %d", idx);
        }
        printf("\n");
    }
    return 0;
}
