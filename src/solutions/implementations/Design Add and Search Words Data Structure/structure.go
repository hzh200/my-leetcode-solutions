type WordDictionary struct {
    root *Node
}

type Node struct {
    val byte
    children []*Node
    isLeaf bool
}

func Constructor() WordDictionary {
    return WordDictionary{
        root: &Node{
            0, 
            make([]*Node, 0),
            false,
        },
    }
}

func (this *WordDictionary) AddWord(word string)  {
    curNode := this.root
    for i, c := range []byte(word) {
        preNode := curNode
        for _, child := range curNode.children {
            if child.val == c {
                curNode = child
                break
            }
        }
        if curNode == preNode {
            node := &Node{c, make([]*Node, 0), false}
            curNode.children = append(curNode.children, node)
            curNode = node
        }
        if i == len([]byte(word)) - 1 {
            curNode.isLeaf = true
        }
    }
}

func (this *WordDictionary) Search(word string) bool {
    var SearchCore func(node *Node, i int) bool
    SearchCore = func(node *Node, i int) bool {
        if node.isLeaf && i == len(word) {
            return true
        }
        if i == len(word) {
            return false
        }
        res := false
        for _, child := range node.children {
            
            if string(word[i]) == "." || word[i] == child.val {
                if SearchCore(child, i + 1) == true {
                    res = true
                    break
                }
            }
        }
        return res
    }
    return SearchCore(this.root, 0)
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */