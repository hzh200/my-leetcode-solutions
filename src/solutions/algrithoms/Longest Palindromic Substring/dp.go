func longestPalindrome(s string) string {
  n := len(s)
  dp := make([][]bool, n)
  for i := 0; i < n; i++ {
      dp[i] = make([]bool, n)
  }
  res := []int{0, 0}
  for l := 0; l < n; l++ {
      for i := 0; i + l < n; i++ {
          if s[i] == s[i + l] && (l < 2 || dp[i + 1][i + l - 1]) {
              dp[i][i + l] = true
              if l > res[1] - res[0] {
                  res = []int{i, i + l}
              }
          }
      }
  }
  return s[res[0] : res[1] + 1]
}
