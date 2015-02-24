#!/usr/bin/env python
# encoding: utf8

# Given a string containing just the characters '(', ')', '{', '}', 
# '[' and ']', determine if the input string is valid.
# The brackets must close in the correct order, "()" and 
# "()[]{}" are all valid but "(]" and "([)]" are not.

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        for c in s:
            if c in ('(', '{', '['):
                stack.append(c)
            elif c in (')', '}', ']'):
                if len(stack) < 1:
                    return False
                left = stack.pop()
                if (left, c) not in (('(', ')'), ('{', '}'), ('[', ']')):
                    return False
            else:
                return False

        if len(stack) != 0:
            return False
        return True
                    
def main():
    s = "({[]})"
    sol = Solution()
    print sol.isValid(s)

if __name__ == "__main__":
    main()
