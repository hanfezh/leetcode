// 628. Maximum Product of Three Numbers.
// Given an integer array, find three numbers whose
// product is maximum and output the maximum product.
package main

import "fmt"
import "math"

func maximumProduct(nums []int) int {
	if len(nums) < 3 {
		return 0
	}

	min1 := math.MaxInt32
	min2 := math.MaxInt32
	max1 := math.MinInt32
	max2 := math.MinInt32
	max3 := math.MinInt32

	for _, val := range nums {
		if val < min1 {
			min2 = min1
			min1 = val
		} else if val < min2 {
			min2 = val
		}

		if val > max3 {
			max1 = max2
			max2 = max3
			max3 = val
		} else if val > max2 {
			max1 = max2
			max2 = val
		} else if val > max1 {
			max1 = val
		}
	}

	max1 = max1 * max2 * max3
	max2 = min1 * min2 * max3
	if max1 > max2 {
		return max1
	}
	return max2
}

func main() {
	nums := []int{1, 2, 3, 4}
	fmt.Printf("Maximum product: %v\n", maximumProduct(nums))
}
