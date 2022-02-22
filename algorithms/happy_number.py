#!/usr/bin/python
# -*- coding: utf-8 -*-
# 202. Happy Number https://leetcode.com/problems/happy-number/

import unittest

class Solution:
    def isHappy(self, n: int) -> bool:
        replace = lambda x: sum(int(i) ** 2 for i in str(x))
        slow = fast = n
        while True:
            slow = replace(slow)
            fast = replace(replace(fast))
            if slow == fast:
                break
        return (slow == 1)

class TestSolution(unittest.TestCase):
    def test_isHappy(self):
        sol = Solution()
        self.assertTrue(sol.isHappy(19))
        self.assertFalse(sol.isHappy(2))

if __name__ == '__main__':
    unittest.main()

