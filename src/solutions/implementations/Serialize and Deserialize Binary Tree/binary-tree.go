/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 type Codec struct {
    // str string
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
    var serializeCore func(node *TreeNode) string
    serializeCore = func(node *TreeNode) string {
        if node != nil {
            left := serializeCore(node.Left)
            right := serializeCore(node.Right)
            return fmt.Sprintf("(%s) %d (%s)", left, node.Val, right)
        } else {
            return "X"
        }
    }
    s := serializeCore(root)
    fmt.Println(s)
    return s;
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {    
    var deserializeCore func() *TreeNode
    deserializeCore = func() *TreeNode {
        // fmt.Println(data)
        if data[0] == 'X' {
            data = data[1:]
            return nil
        }
        // left, right, val := "", "", 0
        // fmt.Sscanf(data, "(%s) %d (%s)", &left, &val, &right)
        // return &TreeNode{Val: val, Left: deserializeCore(left), Right: deserializeCore(right)}
        node := &TreeNode{}
        data = data[1:]
        node.Left = deserializeCore()
        data = data[1:]
        data = data[1:]
        i := 0
        for data[i] != ' ' {
            i++
        }
        node.Val, _ = strconv.Atoi(data[:i])
        data = data[i + 1:]
        data = data[1:]
        node.Right = deserializeCore()
        data = data[1:]
        return node
    }
    return deserializeCore()
}


/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */