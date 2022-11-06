/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */

// @lc code=start
package main

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, v := range nums {
		if p, has := m[target-v]; has {
			return []int{p, i}
		} else {
			m[v] = i
		}
	}
	return nil
}

// @lc code=end
