# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
val= {}
class Solution(object):
            def recurse(self, root, num):
        if root == None:
            return
        else:
            if num in val:
                val[num].append(root.val)
            else:
                val[num] = [root.val]
            self.recurse(root.left, num+1)
            self.recurse(root.right, num+1)
                        def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = []
        num = self.recurse(root, 0)
        # print(num)
        for i in range(len(val)):
            ret.append(val[i])
        val.clear()
        return ret
        