# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]
        :
        d = {}
        for i in to_delete:
            d[i] = 0
                sol = []
        def solve(root):
            if root == None:
                return
            else:
                # if root.left != None:
                #     solve(root.left)
                # if root.right != None:
                #     solve(root.right)
                                                                if root.left!= None and root.left.val in d:
                    if root.left.left != None: 
                        if root.left.left.val not in d: sol.append(root.left
                            .left)
                        solve(root.left.left)
                    if root.left.right != None:
                        # print(root.left.right.val)
                        if root.left.right.val not in d: sol.append(root.left
                            .right)
                        solve(root.left.right)
                    root.left = None
                if root.right != None and root.right.val in d:
                    if root.right.right != None: 
                        if root.right.right.val not in d: sol.append(root
                            .right.right)
                        solve(root.right.right)
                    if root.right.left != None:
                        if root.right.left.val not in d: sol.append(root.right
                            .left)
                        solve(root.right.left)
                    root.right = None
                if root.left != None:
                    if root.val in d: sol.append(root.left)
                    solve(root.left)
                if root.right != None:
                    if root.val in d: sol.append(root.right)
                    solve(root.right)
        if (root.val not in d):
            sol.append(root)
            solve(root)
        else:
            if root.left != None:
                if root.left.val not in d: sol.append(root.left)
                solve(root.left)
            if root.right != None:
                if root.right.val not in d: sol.append(root.right)
                solve(root.right)
        return sol
                        