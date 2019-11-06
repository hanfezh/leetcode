/*
 * =====================================================================================
 *
 *       Filename:  first_bad_version.cpp
 *
 *    Description:  First Bad Version: You are a product manager and currently leading a 
 *                  team to develop a new product. Unfortunately, the latest version of 
 *                  your product fails the quality check. Since each version is 
 *                  developed based on the previous version, all the versions after a 
 *                  bad version are also bad.
 *
 *        Version:  1.0
 *        Created:  08/30/18 11:23:50
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
#include <stdint.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    return version >= 4 ? true : false;
}

// Iterative
class Solution1
{
public:
    int firstBadVersion(int n)
    {
        while (isBadVersion(n))
        {
            n--;
        }
        while (!isBadVersion(n))
        {
            n++;
        }

        return n;
    }
};

// Binary search
class Solution2
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        while (left < right)
        {
            int mid = ((int64_t)left + right) / 2;
            if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        // left == right
        return left;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    int num = 10;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }
    int bad_ver = Solution().firstBadVersion(num);
    printf("%d -> %d\n", num, bad_ver);
    return 0;
}
