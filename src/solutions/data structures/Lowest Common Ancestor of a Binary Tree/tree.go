/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 var target *TreeNode 

 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	 lowestCommonAncestorCore(root, p, q)
	 return target
 }
 
 func lowestCommonAncestorCore(root, p, q *TreeNode) bool {
	 l, r := false, false
	 if root.Left != nil {
		 l = lowestCommonAncestorCore(root.Left, p, q)
	 }
	 if root.Right != nil {
		 r = lowestCommonAncestorCore(root.Right, p, q)
	 }
	 if (root == p || root == q) && (l || r) {
		 target = root
		 return false 
	 }
	 if l && r {
		 target = root
		 return false 
	 }
	 if l || r {
		 return true
	 } 
	 if (root == p || root == q) && (!l && !r) {
		 return true
	 }
	 return false
 }