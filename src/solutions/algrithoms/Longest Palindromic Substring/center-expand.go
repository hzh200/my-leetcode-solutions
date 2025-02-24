func longestPalindrome(s string) string {
  n := len(s)
  res := []int{0, 0}
  for i := 0; i < n; i++ {
      centerExpand(s, i, i, &res)
      if i != n - 1 {
          centerExpand(s, i, i + 1, &res)
      }
  }
  return s[res[0] : res[1] + 1]
}

func centerExpand(s string, left int, right int, res *[]int) {
  for left >= 0 && right <= len(s) - 1 && s[left] == s[right] {
      left--
      right++
  }
  left++
  right--
  if right - left > (*res)[1] - (*res)[0] {
      (*res)[0] = left
      (*res)[1] = right
  }
}
