/*
 * =====================================================================================
 *
 *       Filename:  daily_temperatures.cpp
 *
 *    Description:  739. Daily Temperatures.
 *
 *        Version:  1.0
 *        Created:  04/09/19 12:13:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>

class Solution
{
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temps)
    {
        std::stack<int> idxes;
        std::vector<int> warmer_days(temps.size(), 0);
        for (int i = 0; i < temps.size(); i++)
        {
            while (!idxes.empty() && (temps[i] > temps[idxes.top()]))
            {
                int idx = idxes.top();
                idxes.pop();
                warmer_days[idx] = i - idx;
            }
            idxes.push(i);
        }

        return warmer_days;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    if (argc > 2)
    {
        temps.clear();
        for (int i = 1; i < argc; i++)
        {
            temps.push_back(atoi(argv[i]));
        }
    }

    auto warmer_days = Solution().dailyTemperatures(temps);
    for (auto n: warmer_days)
    {
        printf("%d ", n);
    }
    printf("\n");
    return 0;
}
