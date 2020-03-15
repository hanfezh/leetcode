// 202. Happy Number: https://leetcode.com/problems/happy-number
// Author: xianfeng.zhu@gmail.com

package main

import "fmt"
import "math"

func isHappy(n int) bool {
	trans := func(val int) int {
		sum := 0.0
		for val != 0 {
			sum += math.Pow(float64(val%10), float64(2))
			val /= 10
		}
		return int(sum)
	}

	nums := make(map[int]int)
	nums[1] = 1

	m := n
	for true {
		val, ok := nums[m]
		if ok {
			m = val
			break
		}
		val = trans(m)
		nums[m] = val
		m = val
	}
	return (m == 1)
}

func main() {
	n := 2
	fmt.Printf("Input: %d\n", n)
	fmt.Printf("Output: %v\n", isHappy(n))
}
