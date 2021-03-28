from collections import Counter
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
in_m = Counter()
pre_m = Counter()
class Solution(object):
    def solve(self, preorder, inorder, ret):
        if len(inorder) == 0:
            ret.val = None
            return
        elif len(inorder) == 1:
            # print('end of recursion :', preorder)
            ret.val = inorder[0]
            return
        else:
            root = preorder[0]
            # print('root is: ', root, in_m[root])
            # print(inorder, " ", preorder)
            i_index = 0
            p_index = 0
            for i in range(len(inorder)):
                if inorder[i] == root:
                    i_index = i
                if preorder[i] == root:
                    p_index = i
            inorder_left = inorder [ 0:i_index ]
            inorder_right = inorder [ i_index + 1 : ] 
            # print(inorder_left, " ", inorder_right)
            preorder_left = preorder[ p_index+ 1: p_index + len(inorder_left) 
                + 1 ]
            preorder_right = preorder[ p_index + len(inorder_left) + 1: ]
            # print(preorder_left, " ", preorder_right)
            ret.val = root
            if len(inorder_left) > 0:
                ret.left = TreeNode(0, None, None)
                self.solve(preorder_left, inorder_left, ret.left)
            if len(inorder_right) > 0:
                ret.right = TreeNode(0,None, None)
                self.solve(preorder_right, inorder_right, ret.right)
                    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        for i in range(len(inorder)):
            in_m[inorder[i]] = i
            pre_m[ preorder[i] ] = i
        ret = TreeNode(0, None, None)
        self.solve(preorder, inorder, ret)
        return ret
                        