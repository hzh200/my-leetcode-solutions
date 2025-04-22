func findUnsortedSubarray(nums []int) int {
    minStack := make([][]int, 0)
    minFlag := false
    for i := 0; i < len(nums); i++ {
        if len(minStack) != 0 && nums[i] < minStack[len(minStack) - 1][0] {
            for len(minStack) != 0 && nums[i] < minStack[len(minStack) - 1][0] {
                minStack = minStack[:len(minStack) - 1]
            }
            minFlag = true
        }
        if (!minFlag) {
            minStack = append(minStack, []int{nums[i], i + 1})
        }
    }
    maxStack := make([][]int, 0)
    maxFlag := false
    for i := len(nums) - 1; i >= 0; i-- {
        if len(maxStack) != 0 && nums[i] > maxStack[len(maxStack) - 1][0] {
            for len(maxStack) != 0 && nums[i] > maxStack[len(maxStack) - 1][0] {
                maxStack = maxStack[:len(maxStack) - 1]
            }
            maxFlag = true
        }
        if (!maxFlag) {
            maxStack = append(maxStack, []int{nums[i], len(nums) - i})
        }
    }
    left, right := 0, 0
    if len(minStack) != 0 {
        left = minStack[len(minStack) - 1][1]
    }
    if len(maxStack) != 0 {
        right = maxStack[len(maxStack) - 1][1]
    }
    if left + right >= len(nums) {
        return 0
    }
    return len(nums) - left - right
}