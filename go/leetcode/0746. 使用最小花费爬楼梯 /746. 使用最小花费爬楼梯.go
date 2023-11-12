package leetcode

func minCostClimbingStairs(cost []int) int {
	n := len(cost)
	dp := make([]int, n+1) // dp[i] 表示达到下标 i 的最小花费
	for i := 2; i <= n; i++ {
		dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
	}
	return dp[n]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minCostClimbingStairs2(cost []int) int {
	n := len(cost)
	pre, cur := 0, 0
	for i := 2; i <= n; i++ {
		pre, cur = cur, min(cur+cost[i-1], pre+cost[i-2])
	}
	return cur
}
