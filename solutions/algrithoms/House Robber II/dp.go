func rob(nums []int) int {
  n := len(nums)
  if n == 1 {
      return nums[0]
  }
  if n == 2 {
      return max(nums[0], nums[1])
  }
  return max(robCore(nums[1:]), robCore(nums[:n - 1]))
}

func robCore(nums []int) int {
  n := len(nums)
  dp := make([]int, n)
  dp[0] = nums[0]
  dp[1] = max(nums[0], nums[1])
  for i := 2; i < n; i++ {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
  }
  return dp[n - 1]
}
