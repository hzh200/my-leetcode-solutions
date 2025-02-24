func minDistance(word1 string, word2 string) int {
  dp := make([][]int, len(word1) + 1)
  for i := 0; i < len(word1) + 1; i++ {
      dp[i] = make([]int, len(word2) + 1)
  }
  for i := 0; i < len(word1); i++ {
      dp[i + 1][0] = i + 1
  }
  for i := 0; i < len(word2); i++ {
      dp[0][i + 1] = i + 1
  }
  for i := 0; i < len(word1); i++ {
      for j := 0; j < len(word2); j++ {
          dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1]) + 1
          if word1[i] == word2[j] {
              dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j])
          } else {
              dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1)
          }
      }
  }
  return dp[len(word1)][len(word2)]
}
