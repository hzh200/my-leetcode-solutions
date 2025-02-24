func twoSum(nums []int, target int) []int {
  cache := make(map[int]int)
  for i := 0; i < len(nums); i++ {
      if val, ok := cache[nums[i]]; ok {
          return []int{i, val}
      } else {
          cache[target - nums[i]] = i
      }
  }
  return []int{};
}
