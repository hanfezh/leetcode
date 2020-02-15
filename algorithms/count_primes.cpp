// 204. Count Primes: https://leetcode.com/problems/count-primes
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Brute force
class Solution1
{
public:
    int countPrimes(int n)
    {
        std::vector<int> primes(1, 2);

        for (int i = 3; i < n; i++)
        {
            bool is_prime = true;
            for (auto j: primes)
            {
                if ((j * j) <= i && (i % j) == 0)
                {
                    is_prime = false;
                    break;
                }
            }

            if (is_prime)
            {
                primes.push_back(i);
            }
        }
        
        return (n > 2 ? primes.size() : 0);
    }
};

// Sieve of Eratosthenes
class Solution2
{
public:
    int countPrimes(int n)
    {
        std::vector<bool> primes(n, true);
        for (int i = 2; i * i < n; i++)
        {
            if (!primes[i])
            {
                continue;
            }

            for (int j = i * i; j < n; j += i)
            {
                primes[j] = false;
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (primes[i])
            {
                count++;
            }
        }

        return count;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    int n = 10;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }
    int count = Solution().countPrimes(n);
    printf("Input: %d\n", n);
    printf("Output: %d\n", count);
    return 0;
}
