func sortColors(nums []int)  {
    p1, p2 := 0, len(nums) - 1
    for i := 0; i <= p2; i++ {
        for i <= p2 && nums[i] == 2 {
            swap(p2, i, nums)
            p2--
        }
        if nums[i] == 0 {
            swap(p1, i, nums)
            p1++
        } 
    }
}

func swap(i, j int, nums []int) {
    tmp := nums[i]
    nums[i] = nums[j]
    nums[j] = tmp
}