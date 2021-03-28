# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: 
        TreeNode) -> TreeNode:
        ret = None
        def solve(original, cloned, target):
            if (original == target):
                # print("hello ", target)
                return cloned
            else:
                if original == None:
                    print('hello')
                    return
                if original.left != None:
                    l = solve(original.left, cloned.left, target)
                    # print(l)
                    if l != None:
                        return l
                if original.right != None:
                    r = solve(original.right, cloned.right, target)
                    if r != None:
                        return r
                        ret = solve(original, cloned, target)
        return ret