#! /usr/bin/env python
# encoding: utf8

# Single Number 
# Given an array of integers, every element appears twice except for one. Find that single one.

__author__ = "ufengzhu<xianfeng.zhu@gmail.com>"

class Solution(object):
	def singleNumber(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		num = 0
		for n in nums:
			num ^= n
		return num

def main():
	sol = Solution()
	num = sol.singleNumber([1, 2, 3, 4, 4, 3, 2, 1, 10])
	print num

if __name__ == "__main__":
	main()
