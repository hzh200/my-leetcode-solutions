func getPermutation(n int, k int) string {
    pows := make([]int, n)
    pows[0] = 1
    for i := 1; i < n; i++ {
        pows[i] = pows[i - 1] * i
    }
    candidates := make([]int, n)
    for i := 0; i < n; i++ {
        candidates[i] = i + 1
    }
    k--
    res := make([]int, n)
    for i := 0; i < n; i++ {
        index := k / pows[n - i - 1]
        k = k % pows[n - i - 1]
        fmt.Println(candidates, index, k)
        res[i] = candidates[index]
        candidates = append(candidates[:index], candidates[index + 1:]...)
    }
    
    builder := strings.Builder{}
    for i := 0; i < n; i++ {
        builder.WriteByte('0' + byte(res[i]))
    }
    return builder.String()
}