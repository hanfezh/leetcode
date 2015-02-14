#!/usr/bin/env python
# encoding: utf8

# String to Integer (atoi): Implement atoi to convert a string to an integer. 

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

class Solution:
    # @return an integer
    def atoi(self, s):
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -(INT_MAX + 1)
        slen = len(s)
        if slen == 0:
            return 0

        # Ignore blank
        i = 0
        while s[i] in (' ', '\t', '\n', '\0'):
            i += 1
        if i != 0:
            s = s[i:]

        mlen = str(INT_MIN)
        slen = len(s)
        if slen > mlen or slen == 0:
            return 0

        # Handle flag
        flag = 1
        if s[0] == '+':
            s = s[1:]
        elif s[0] == '-':
            flag = -1
            s = s[1:]

        n = 0
        for i in s:
            if i not in "0123456789":
                break
            i = int(i)
            n = n * 10 + i

        n = (n * flag)
        if n > INT_MAX:
            n = INT_MAX
        elif n < INT_MIN:
            n = INT_MIN
        return n

def main():
    s = "2147483648"
    sol = Solution()
    print sol.atoi(s)

if __name__ == "__main__":
    main()
