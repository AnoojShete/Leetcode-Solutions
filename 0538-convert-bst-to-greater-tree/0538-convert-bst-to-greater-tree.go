/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var sum int
func convertBST(root *TreeNode) *TreeNode {
    sum = 0
    var solve func(*TreeNode)
    solve = func(node *TreeNode) {
        if node == nil {
            return
        }
        solve(node.Right)
        sum += node.Val
        node.Val = sum
        solve(node.Left)
    }
    solve(root)
    return root
}