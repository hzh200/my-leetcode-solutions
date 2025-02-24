type Point struct {
    x int
    height int
}

type PriorityQueue []int

func (queue PriorityQueue) Len() int {
    return len(queue)
}

func (queue PriorityQueue) Swap(i, j int) {
    queue[i], queue[j] = queue[j], queue[i]
}

func (queue PriorityQueue) Less(i, j int) bool {
    return queue[i] > queue[j]
}

func (queue *PriorityQueue) Push(v interface{}) {
    *queue = append(*queue, v.(int))
}

func (queue *PriorityQueue) Pop() interface{} {
    newQueue := *queue
    res := newQueue[len(newQueue) - 1]
    *queue = newQueue[:len(newQueue) - 1]
    return res
}

func (queue *PriorityQueue) Remove(v interface{}) {
    // tmp := *queue
    // *queue = make([]int, 0)
    // for _, item := range tmp {
    //     if v.(int) == item {
    //         continue
    //     }
    //     heap.Push(queue, item)
    // }
    index := -1
    for i, item := range *queue {
        if item == v.(int) {
            index = i
            break
        }
    }
    if index != -1 {
        *queue = append((*queue)[:index], (*queue)[index + 1:]...)
    }
    heap.Init(queue)
}

func getSkyline(buildings [][]int) [][]int {
    ps := make([]Point, 0)
    for _, building := range buildings {
        ps = append(ps, Point{x: building[0], height: -building[2]})
        ps = append(ps, Point{x: building[1], height: building[2]})
    }
    sort.Slice(ps, func (i, j int) bool {
        if ps[i].x != ps[j].x {
            return ps[i].x < ps[j].x
        }
        return ps[i].height < ps[j].height
    })
    prev := 0
    queue := PriorityQueue{}
    queue.Push(prev)
    res := make([][]int, 0)
    for _, p := range ps {
        if p.height < 0 {
            heap.Push(&queue, -p.height)
        } else {
            queue.Remove(p.height)
        }
        cur := queue[0]
        if prev != cur {
            res = append(res, []int{p.x, cur})
            prev = cur
        }
    }
    return res
}