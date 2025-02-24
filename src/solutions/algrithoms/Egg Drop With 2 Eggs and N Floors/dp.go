func twoEggDrop(n int) int {
    f := make([]int, n + 1)
    for i := 1; i < n + 1; i++ {
        f[i] = math.MaxInt
        for k := 1; k <= i; k++ {
            f[i] = min(f[i], max(k - 1, f[i - k]) + 1)
        }
    }
    return f[n]
}