# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: TreeNode):
        vals = []
        def solve(r):
            if (r):
                solve(r.left)
                vals.append(r.val)
                solve(r.right)
        solve(root)
        self.vals = vals
        # print(self.vals)
        self.index = 0
            def next(self) -> int:
        ret = self.vals[self.index]
        self.index+=1
        return ret
                def hasNext(self) -> bool:
        return self.index < len(self.vals)
# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()