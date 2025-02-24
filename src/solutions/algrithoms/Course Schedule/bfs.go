func canFinish(numCourses int, prerequisites [][]int) bool {
    inDegrees := make([]int, numCourses)
    edges := make([][]int, numCourses)
    visited := make([]int, numCourses)
    for _, pre := range prerequisites {
        inDegrees[pre[0]]++
        edges[pre[1]] = append(edges[pre[1]], pre[0])
    }

    count := 0
    queue := make([]int, 0)
    for {
        for i, inDegree := range inDegrees {
            if inDegree == 0 && visited[i] == 0 {
                queue = append(queue, i)
                visited[i] = 1
            }
        }
        if len(queue) == 0 {
            break
        }
        for len(queue) != 0 {
            for _, edge := range edges[queue[0]] {
                inDegrees[edge]--
            }
            queue = queue[1:]
            count++
        }
    }

    return count == numCourses
}