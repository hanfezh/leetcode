#!/usr/bin/env python
# encoding: utf8

# Reverse Integer: Reverse digits of an integer.
# Example1: x = 123, return 321
# Example2: x = -123, return -321

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

class Solution:
    # @return an integer
    def reverse(self, x):
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -(INT_MAX + 1)
        flag = 1
        if x < 0:
            flag = -1
            x = -x
        i = 0
        n = 0
        while x != 0 and x != -1:
            n = n * 10 + x % 10
            x /= 10
            i += 1

        n = (n * flag)
        if n > INT_MAX or n < INT_MIN:
            return 0
        return n

def main():
    # n = -1200003
    # n = 1534236469
    n = -2147483648
    sol = Solution()
    print n
    print sol.reverse(n)

if __name__ == "__main__":
    main()
