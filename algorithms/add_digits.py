#!/usr/bin/python
# -*- coding: utf-8 -*-
# 258. Add Digits https://leetcode.com/problems/add-digits/

import unittest

class Solution:
    def addDigits(self, num: int) -> int:
        ret = int(num / 10)
        if not ret:
            return num
        else:
            return self.addDigits(self.addDigits(ret) + num % 10)

class TestSolution(unittest.TestCase):
    def test_addDigits(self):
        sol = Solution()
        self.assertEqual(sol.addDigits(23), 5)
        self.assertEqual(sol.addDigits(10), 1)
        self.assertEqual(sol.addDigits(1235), 2)

if __name__ == '__main__':
    unittest.main()
