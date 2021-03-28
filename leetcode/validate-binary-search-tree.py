# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        vals = []
        if root == None:
            return True
        def solve(root):
            if root.left == None and root.right == None:
                vals.append(root.val)
            else:
                if (root.left != None):
                    solve(root.left)
                vals.append(root.val)
                if (root.right!=None):
                    solve(root.right)
        solve(root)
        if (all(vals[i] < vals[i+1] for i in range(len(vals)-1))):
            return True
        else:
            return False
        