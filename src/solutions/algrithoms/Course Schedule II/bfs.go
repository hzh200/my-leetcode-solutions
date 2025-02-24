func findOrder(numCourses int, prerequisites [][]int) []int {
    inDegrees := make([]int, numCourses)
    edges := make([][]int, numCourses)
    visited := make([]int, numCourses)
    seq := make([]int, 0)
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
            seq = append(seq, queue[0])
            queue = queue[1:]
            count++
        }
    }

    if count != numCourses {
        return []int{}
    }
    return seq
}