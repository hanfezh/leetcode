#!/usr/bin/env python
# encoding: utf8

# Determine whether an integer is a palindrome. Do this without extra space.

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

class Solution:
    def _isPalindrome(self, num, size):
        if size < 2:
            return True

        # size >= 2
        head = (num / (10 ** (size - 1))) % 10
        tail = num % 10
        # print "num = %d, size = %d, head = %d, tail = %d" % (num, size, head, tail)
        if head == tail:
            num %= (10 ** (size - 1))
            num /= 10
            return self._isPalindrome(num, size - 2)
        else:
            return False

    # @return a boolean
    def isPalindrome(self, x):
        # x = abs(x)
        if x < 0:
            return False
        n = x
        i = 1
        while n >= 10:
            n /= 10
            i += 1
        return self._isPalindrome(x, i)

def main():
    num = -2147447412
    sol = Solution()
    print sol.isPalindrome(num)

if __name__ == "__main__":
    main()
