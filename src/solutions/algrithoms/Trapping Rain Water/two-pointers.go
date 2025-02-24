func trap(height []int) int {
    l, r := 0, len(height) - 1
    lWall, rWall := height[l], height[r]
    res := 0
    for l < r {
        if lWall >= rWall {
            r--
            if height[r] < rWall {
                res += (rWall - height[r])
            } else {
                rWall = height[r]
            }
        } else {
            l++
            if height[l] < lWall {
                res += (lWall - height[l])
            } else {
                lWall = height[l]
            }
        }
    }
    return res
}