# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        count = []
        total = []
        def solve(root):
            if root:
                ret1 = solve(root.left)
                ret2 = solve(root.right)
                t = ret1[0] + ret2[0]
                c = ret1[1] + ret2[1]
                count.append(c + 1)
                total.append(t + root.val)
                return (t + root.val, c+1)
            else:
                return (0,0)
        a = solve(root)
        av = [total[i] / count[i] for i in range(len(count))]
        return max(av)
                            