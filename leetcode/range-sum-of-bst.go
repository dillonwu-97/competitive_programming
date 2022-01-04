/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ret int = 0
func recurse(root *TreeNode, low int, high int) {
    if (root.Val >= low && root.Val <= high) {
        fmt.Println(root.Val)
        ret += root.Val
    }
    if root.Left != nil {
        recurse(root.Left, low, high)
    } 
    if root.Right != nil {
        recurse(root.Right, low, high)
    }
    }
func rangeSumBST(root *TreeNode, low int, high int) int {
    ret = 0
    recurse(root, low, high)
    return ret
    }