#! /usr/bin/env python
# encoding: utf8

# Ugly Number
# Write a program to check whether a given number is an ugly number.
# Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
# For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
# Note that 1 is typically treated as an ugly number.

__author__ = "ufengzhu<xianfeng.zhu@gmail.com>"

class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 0:
            return False

        while num != 1:
            if num % 2 == 0:
                num /= 2
            elif num % 3 == 0:
                num /= 3
            elif num % 5 == 0:
                num /= 5
            else:
                return False

        return True

def main():
    sol = Solution()
    num = 14
    print "%d is ugly number? %s." % (num, sol.isUgly(num))

if __name__ == "__main__":
    main()

