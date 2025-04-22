func dailyTemperatures(temperatures []int) []int {
    n := len(temperatures)
    res := make([]int, n)
    stack := make([][]int, 0)
    for i := 0; i < n; i++ {
        temp := temperatures[i]
        for len(stack) != 0 && stack[len(stack) - 1][0] < temp {
            t := stack[len(stack) - 1]
            stack = stack[:len(stack) - 1]
            res[t[1]] = i - t[1]
        }
        stack = append(stack, []int{temp, i})
    }
    return res
}