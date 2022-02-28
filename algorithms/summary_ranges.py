#!/usr/bin/python
# -*- coding: utf-8 -*-
# 228. Summary Ranges https://leetcode.com/problems/summary-ranges/

from typing import List
import unittest

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ranges = []
        for n in nums:
            if ranges and ranges[-1] and (ranges[-1][-1] + 1 == n):
                ranges[-1].append(n)
            else:
                ranges.append([n])
        return [str(r[0]) if len(r) == 1 else f'{r[0]}->{r[-1]}' for r in ranges]

class TestSolution(unittest.TestCase):
    def test_summaryRanges(self):
        sol = Solution()
        self.assertEqual(sol.summaryRanges([]), [])
        self.assertEqual(sol.summaryRanges([1]), ['1'])
        self.assertEqual(sol.summaryRanges([0, 1, 2, 4, 5, 7]), ['0->2', '4->5', '7'])

if __name__ == '__main__':
    unittest.main()
