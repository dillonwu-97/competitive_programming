# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        def countPairs(self, root: TreeNode, distance: int) -> int:
        ret = 0
        if root == None:
            return 0
        l = []
        def find_leaves (root, path):
            if root.left == None and root.right == None:
                l.append(path + [root])
            else:
                if root.left != None:
                    find_leaves(root.left, path + [root])
                if root.right != None:
                    find_leaves(root.right, path + [root])
                def find_lca(l1, l2):
            i = 0
            while (l1[i] == l2[i]):
                i+=1
            return len(l1) - i + len(l2) - i
                find_leaves(root, [])
        for i in range(len(l)):
            for j in range(i+1, len(l)):
                # print(len(l[i]), len(l[j]))
                temp = find_lca(l[i], l[j])
                if temp <= distance:
                    ret+=1
                                return ret
        