type MinStack struct {
  arr []int
  minArr []int
}


func Constructor() MinStack {
  return MinStack{arr: make([]int, 0), minArr: make([]int, 0)}
}


func (this *MinStack) Push(val int)  {
  this.arr = append(this.arr, val)
  for i := 0; i < len(this.minArr); i++ {
      if this.minArr[i] < val {
          this.minArr = append(this.minArr[:i + 1], this.minArr[i:]...)
          this.minArr[i] = val
          break
      }
  }
  if len(this.minArr) < len(this.arr) {
      this.minArr = append(this.minArr, val)
  }
}


func (this *MinStack) Pop()  {
  top := this.arr[len(this.arr) - 1]
  this.arr = this.arr[:len(this.arr) - 1]
  for i := 0; i < len(this.minArr); i++ {
      if this.minArr[i] == top {
          this.minArr = append(this.minArr[:i], this.minArr[i + 1:]...)
          break
      }
  }
}


func (this *MinStack) Top() int {
  return this.arr[len(this.arr) - 1]
}


func (this *MinStack) GetMin() int {
  return this.minArr[len(this.minArr) - 1]
}


/**
* Your MinStack object will be instantiated and called as such:
* obj := Constructor();
* obj.Push(val);
* obj.Pop();
* param_3 := obj.Top();
* param_4 := obj.GetMin();
*/
