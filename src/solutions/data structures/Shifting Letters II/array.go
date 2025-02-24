func shiftingLetters(s string, shifts [][]int) string {
    diffs := make([]int, len(s) + 1) // difference array
    for _, s := range shifts {
        if s[2] == 0 {
            diffs[s[0]] -= 1
            diffs[s[1] + 1] += 1
        } else {
            diffs[s[0]] += 1
            diffs[s[1] + 1] -= 1
        }
    }
    bytes := []byte(s)
    shift := 0
    for i := 0; i < len(s); i++ {
        shift = (shift + diffs[i]) % 26 + 26
        bytes[i] = (bytes[i] - 'a' + byte(shift)) % 26 + 'a'
    }
    return string(bytes)
}