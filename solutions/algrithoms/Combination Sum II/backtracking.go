func combinationSum2(candidates []int, target int) [][]int {
  slices.Sort(candidates)
  ress := make([][]int, 0)
  res := make([]int, 0)
  combinationSum2Core(candidates, target, 0, 0, res, &ress)
  return ress
}

func combinationSum2Core(candidates []int, target int, index int, sum int, res []int, ress *[][]int) {
  if sum == target {
      *ress = append(*ress, append(make([]int, 0), res...))
  }
  for i, candidate := range candidates[index:] {
      if i != 0 && candidates[index + i] == candidates[index + i - 1] {
          continue
      }
      if candidate <= target - sum {
          combinationSum2Core(candidates, target, index + i + 1, sum + candidate, append(res, candidate), ress)
      }
  }
}
