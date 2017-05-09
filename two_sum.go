// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

package main

import "fmt"

func twoSum(nums []int, target int) []int {
	for i, x := range nums {
		for j, y := range nums[(i + 1):] {
			if (x + y) == target {
				return []int{i, (i + 1 + j)}
			}
		}
	}

	return nil
}

func main() {
	nums := []int{3, 2, 4}
	fmt.Printf("%v\n", twoSum(nums, 6))
}
