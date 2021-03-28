# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict 
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        d = defaultdict(list)
        def solve(root, n):
            if root:
                d[n].append(root.val)
                solve(root.left, n+1)
                solve(root.right, n+1)
                solve(root, 0)
        return sum(d[max(d.keys())])
        