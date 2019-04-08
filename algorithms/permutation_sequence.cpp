/*
 * =====================================================================================
 *
 *       Filename:  permutation_sequence.cpp
 *
 *    Description:  60. Permutation Sequence.
 *
 *        Version:  1.0
 *        Created:  04/03/19 07:36:31
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
#include <string>
#include <vector>

class Solution
{
public:
    std::string getPermutation(int n, int k)
    {
        std::vector<int> digits;
        for (int i = 1; i <= n; i++)
        {
            digits.push_back(i);
        }

        std::vector<int> factorials(n + 1);
        factorials[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            factorials[i] = factorials[i - 1] * i;
        }

        std::string perm;
        k--;

        for (int i = 1; i <= n; i++)
        {
            int idx = k / factorials[n - i];
            perm += (char)(digits[idx] + '0');
            digits.erase(digits.begin() + idx);
            k %= factorials[n - i];
        }

        return perm;
    }
};

int main(int argc, char* argv[])
{
    int n = 3;
    int k = 3;
    if (argc == 3)
    {
        n = atoi(argv[1]);
        k = atoi(argv[2]);
    }
    auto perm = Solution().getPermutation(n, k);
    printf("The permutation is: %s\n", perm.c_str());

    return 0;
}
