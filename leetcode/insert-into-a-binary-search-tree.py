# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
            temp = root
        while (temp.val):
            print("hi")
            if (temp.val >= val):
                print(temp.val)
                if (temp.left == None):
                    temp.left = TreeNode(val)
                    break
                else:
                    temp = temp.left
            elif (temp.val < val):
                if (temp.right == None):
                    temp.right = TreeNode(val)
                    break
                else:
                    temp = temp.right
        return root
                        