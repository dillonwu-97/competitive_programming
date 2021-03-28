# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        ret = [0]
        def solve(root, a, s):
            if root:
                a.append(root.val)
                solve(root.left, a, s)
                solve(root.right, a, s)
                r = 0
                for i in range(len(a)-1, -1, -1):
                    r += a[i]
                    if r == s:
                        ret[0] += 1
                a.pop()
                                                solve(root, [], sum)
        return ret[0]