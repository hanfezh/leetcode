// 33. Search in Rotated Sorted Array
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).
package main

import "fmt"

func search(nums []int, target int) int {
	start := 0
	end := len(nums) - 1
	small := -1
	pivot := -1
	for start < end {
		pivot = (start + end) / 2
		if nums[pivot] < nums[end] {
			end = pivot
		} else {
			start = pivot + 1
		}
	}

	small = start
	start = 0
	end = len(nums) - 1
	for start <= end {
		pivot = (start + end) / 2
		real := (pivot + small) % len(nums)
		if nums[real] < target {
			start = pivot + 1
		} else if nums[real] > target {
			end = pivot - 1
		} else {
			// Found index
			return real
		}
	}

	return -1
}

func main() {
	nums := []int{4, 5, 6, 7, 0, 1, 2}
	target := 3
	idx := search(nums, target)
	fmt.Printf("Found index? %v\n", idx)
}
