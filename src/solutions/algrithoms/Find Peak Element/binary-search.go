func findPeakElement(nums []int) int {
  left, right := 0, len(nums) - 1
  for left < right {
      mid := (left + right) / 2
      // if (mid == 0 || nums[mid] > nums[mid - 1]) && (mid == len(nums) - 1 || nums[mid] > nums[mid + 1]) {
      //     return mid
      // }
      if (mid < len(nums) - 1 && nums[mid] < nums[mid + 1]) || mid == len(nums) - 1 {
        left = mid + 1
      } else {
          right = mid
      }
  }
  return left
}
