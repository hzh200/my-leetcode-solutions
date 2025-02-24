func findOrder(numCourses int, prerequisites [][]int) []int {
    edges := make([][]int, numCourses)
    visited := make([]int, numCourses)
    res := true
    seq := make([]int, 0)
    for _, pre := range prerequisites {
        edges[pre[1]] = append(edges[pre[1]], pre[0])
    }

    var dfs func(int)
    dfs = func(i int) {
        if !res {
            return
        }

        visited[i] = 1
        for _, subIndex := range edges[i] {
            if visited[subIndex] == 0 {
                dfs(subIndex)
                if !res {
                    return
                }     
            } else if visited[subIndex] == 1 {
                res = false
                return
            }
        }
        seq = append(seq, i)
        visited[i] = 2
    }

    for i := 0; i < numCourses; i++ {
        if visited[i] == 0 {
            dfs(i)
        }
    }

    if !res {
        return []int{}
    }

    reversedSeq := make([]int, 0)
    for i := len(seq) - 1; i >= 0; i-- {
        reversedSeq = append(reversedSeq, seq[i])
    }
    return reversedSeq
}