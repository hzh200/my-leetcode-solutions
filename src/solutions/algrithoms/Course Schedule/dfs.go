func canFinish(numCourses int, prerequisites [][]int) bool {
    edges := make([][]int, numCourses)
    visited := make([]int, numCourses)
    res := true
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
        visited[i] = 2
    }

    for i := 0; i < numCourses; i++ {
        if visited[i] == 0 {
            dfs(i)
        }
    }

    return res
}