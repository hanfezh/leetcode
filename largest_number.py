#!/usr/bin/env python
# encoding: utf8

# Given a list of non negative integers, arrange them such that they form the largest number.
# For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

def _str_cmp(a, b, origa, origb):
    if a[0] > b[0]:
        return 1
    elif a[0] < b[0]:
        return -1

    # a[0] == b[0]
    if len(a) > 1 and len(b) > 1:
        return _str_cmp(a[1:], b[1:], origa, origb)
    elif len(a) > 1:
        return _str_cmp(a[1:], origb, a[1:], origb)
    elif len(b) > 1:
        return _str_cmp(origa, b[1:], origa, b[1:])
    else:
        return 0

def str_cmp(a, b):
    return _str_cmp(a, b, a, b)

class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        s = ""
        slist = []
        for i in num:
            slist.append(str(i))
        slist = sorted(slist, str_cmp)
        for i in reversed(slist):
            s = s + i

        while len(s) > 1 and s[0] == '0':
            s = s[1:]

        return s

def main():
    sol = Solution()
    s = sol.largestNumber([3, 30, 34, 5, 9])
    print s

if __name__ == "__main__":
    main()

