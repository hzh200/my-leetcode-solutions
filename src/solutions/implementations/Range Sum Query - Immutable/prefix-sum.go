type NumArray struct {
    Sums []int
}

func Constructor(nums []int) NumArray {
    numArray := NumArray{Sums: make([]int, len(nums))}
    for i := 0; i < len(nums); i++ {
        numArray.Sums[i] = nums[i]
        if i != 0 {
            numArray.Sums[i] += numArray.Sums[i - 1]
        }
    }
    return numArray
}

func (this *NumArray) SumRange(left int, right int) int {
    if left == 0 {
        return this.Sums[right]
    } else {
        return this.Sums[right] - this.Sums[left - 1]
    }
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */