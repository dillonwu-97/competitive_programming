# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        # """
        # :type root: TreeNode
        # :type p: TreeNode
        # :type q: TreeNode
        # :rtype: TreeNode
        # """
        # # Extremely slow
        # p_list = []
        # q_list = []
        # def search(root, v, a):
        #     if root == None:
        #         return
        #     elif root == v:
        #         # print ('a is ', a)
        #         return a + [root]
        #     else:
        #         # print("testing ", root.val)
        #         # print(' v is", ', v)
        #         temp = a
        #         a = search (root.left, v, a + [root])
        #         if (a == None):
        #             a = search (root.right, v,  temp + [root]) 
        #         return a
        # a = search(root, p, [])
        # b = search(root, q, [])
        # min_val = min(len(a), len(b))
        # ret = None
        # for i in range(min_val):
        #     if a[i] != b[i]:
        #         ret = a[i-1]
        #         break
        # if ret == None and len(a) == min_val:
        #     ret = a[-1]
        # elif ret == None and len(b) == min_val:
        #     ret = b[-1]
        # # debug
        # # tempa = []
        # # tempb = []
        # # for i in a:
        # #     tempa.append(i.val)
        # # for i in b:
        # #     tempb.append(i.val)
        # # print(tempa, tempb)
        # return ret
                # Not naive method
        if root in (p, q, None):
            return root
        else:
            l = self.lowestCommonAncestor(root.left, p, q)
            r = self.lowestCommonAncestor(root.right, p, q)
            if l and r:
                return root
            else:
                return l or r
                                                                        