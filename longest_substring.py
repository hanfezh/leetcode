#!/usr/bin/env python
# encoding: utf8

# Given a string, find the length of the longest substring without repeating characters.
# For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
# which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        maxstr = ""
        curstr = ""
        for i in s:
            if i not in curstr:
                curstr = curstr + i
            else:
                if len(curstr) > len(maxstr):
                    maxstr = curstr
                idx = curstr.find(i)
                idx += 1
                curstr = curstr[idx:] + i
        if len(curstr) > len(maxstr):
            maxstr = curstr

        # print maxstr
        return len(maxstr)

def main():
    sol = Solution()
    s = "dvdf"
    print sol.lengthOfLongestSubstring(s)

if __name__ == "__main__":
    main()
            
