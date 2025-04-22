func findKthLargest(nums []int, k int) int {
    n := len(nums)
    var buildNode func(i int)
    buildNode = func (i int) {
        l, r, largest := i * 2 + 1, i * 2 + 2, i
        if l < n && nums[l] > nums[largest] {
            largest = l
        }
        if r < n && nums[r] > nums[largest] {
            largest = r
        }
        if largest != i {
            nums[i], nums[largest] = nums[largest], nums[i]
            buildNode(largest)
        }
    }

    for i := n / 2 - 1; i >= 0; i-- {
        buildNode(i)
    }

    res := make([]int, k)
    for i := 0; i < k; i++ {
        res[i] = nums[0]
        nums[0] = nums[n - 1]
        nums = nums[:n - 1]
        n--
        buildNode(0)
    }
    return res[len(res) - 1]
}