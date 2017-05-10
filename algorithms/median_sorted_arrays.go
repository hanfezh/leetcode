// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

package main

import "fmt"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var nums []int

	for {
		if len(nums1) > 0 && len(nums2) > 0 {
			if nums1[0] < nums2[0] {
				nums = append(nums, nums1[0])
				nums1 = nums1[1:]
			} else {
				nums = append(nums, nums2[0])
				nums2 = nums2[1:]
			}
		} else if len(nums1) > 0 {
			nums = append(nums, nums1[0])
			nums1 = nums1[1:]
		} else if len(nums2) > 0 {
			nums = append(nums, nums2[0])
			nums2 = nums2[1:]
		} else {
			break
		}
	}

	if (len(nums) % 2) != 0 {
		return (float64)(nums[len(nums)/2])
	} else {
		return (float64)(nums[len(nums)/2-1]+nums[len(nums)/2]) / 2.0
	}
}

func main() {
	nums1 := []int{1, 3}
	nums2 := []int{2}
	fmt.Println(findMedianSortedArrays(nums1, nums2))
}
