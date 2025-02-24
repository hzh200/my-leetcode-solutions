func longestPrefix(s string) string {
  n := len(s)
  next := make([]int, n + 1)
  next[0] = -1
  i, j := 0, -1
  for i < n {
      if j == -1 || s[i] == s[j] {
          i++
          j++
          next[i] = j
      } else {
          j = next[j]
      }
  }
  return s[:next[n]]
}
