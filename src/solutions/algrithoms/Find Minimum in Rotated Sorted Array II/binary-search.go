func findMin(nums []int) int {
  left, right := 0, len(nums) - 1
  for nums[left] == nums[right] && left < right {
      right-- // leave at least one equal side element
  }

  if left == right { // len(nums) == 1 || all elements equal with each other
      return nums[left]
  }

  if nums[left] < nums[right] { // ordered list
      return nums[left]
  }

  mid := (left + right) / 2
  for left <= right {
      mid = (left + right) / 2
      if mid < len(nums) - 1 && nums[mid] > nums[mid + 1] {
          return nums[mid + 1]
      }
      if nums[mid] > nums[right] { // compare with the deleting side // [3, 3, 3, 1]
          left = mid + 1
      } else {
          right = mid
      }
  }
  return nums[0]
}
