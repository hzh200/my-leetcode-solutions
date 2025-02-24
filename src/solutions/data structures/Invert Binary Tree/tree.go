/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }

    var invertTreeCore func (node *TreeNode) 
    invertTreeCore = func (node *TreeNode) {
        if node.Left != nil {
            invertTreeCore(node.Left)
        }
        if node.Right != nil {
            invertTreeCore(node.Right)
        }
        tmp := node.Left
        node.Left = node.Right
        node.Right = tmp
    }
    invertTreeCore(root)
    return root
}