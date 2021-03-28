# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        # do a traversal instead and save the index
        ret = []
        def solve(root):
            if root:
                solve(root.left)
                ret.append(root)
                # print(root.val, ret_vals)
                solve(root.right)
        solve(root)
        # print(ret_vals, ret)
        for i in range(len(ret)-1):
            if ret[i] == p:
                return ret[i+1]
        return None
        # print(ret_vals)
        #         def solve(root, p, prev):
#             if root:
#                 if root.val == p:
#                     # print(root.val, prev, p)
#                     if root.right != None: return root.right
#                     elif prev != -1:
#                         if prev.val > root.val: 
#                             return prev
#                     else:
#                         return None
#                 else:
#                     prev = root
#                     r = solve(root.right, p, prev) 
#                     if r == None:
#                         l = solve(root.left, p, prev)
#                     # print(r, l)
#                     return l
#         ret = solve(root, p.val, -1)
#         # print(root.val, p)
#         return ret
                