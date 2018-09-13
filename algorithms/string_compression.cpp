/*
 * =====================================================================================
 *
 *       Filename:  string_compression.cpp
 *
 *    Description:  String Compression: Given an array of characters, compress it in-place.
 *
 *        Version:  1.0
 *        Created:  09/13/18 01:49:25
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
#include <vector>

class Solution
{
public:
    int compress(std::vector<char>& chars)
    {
        if (chars.size() < 1 || chars.size() > 1000)
        {
            return 0;
        }

        auto append_count = [](std::vector<char>& chars, int& index, int count)
        {
            bool exist = false;
            if (count >= 100)
            {
                chars[index++] = (char)('0' + count / 100);
                count %= 100;
                exist = true;
            }
            if (exist || count >= 10)
            {
                chars[index++] = (char)('0' + count / 10);
                count %= 10;
                exist = true;
            }
            if (exist || count > 1)
            {
                chars[index++] = (char)('0' + count);
            }
        };

        char prev = chars[0];
        int count = 1;
        int index = 0;
        for (size_t i = 1; i < chars.size(); i++)
        {
            if (chars[i] == prev)
            {
                count += 1;
            }
            else
            {
                chars[index++] = prev;
                if (count > 1)
                {
                    append_count(chars, index, count);
                }
                prev = chars[i];
                count = 1;
            }
        }

        chars[index++] = prev;
        if (count > 1)
        {
            append_count(chars, index, count);
        }

        return index;
    }
};

int main(int argc, char* argv[])
{
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int num = Solution().compress(chars);
    printf("%d\n", num);
    return 0;
}

