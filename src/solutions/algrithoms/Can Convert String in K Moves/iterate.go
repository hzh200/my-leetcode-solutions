func canConvertString(s string, t string, k int) bool {
    if len(s) != len(t) {
        return false
    }

    diffs := make([]int, 27)
    for i := 0; i < len(s); i++ {
        diff := int(t[i]) - int(s[i])
        if diff < 0 {
            diff += 26
        }
        diffs[diff]++
    }

    fmt.Println(diffs)
    for key, val := range diffs {
        if key == 0 || val == 0 {
            continue
        }

        if key + 26 * (val - 1) > k {
            return false
        }
    }

    return true
}