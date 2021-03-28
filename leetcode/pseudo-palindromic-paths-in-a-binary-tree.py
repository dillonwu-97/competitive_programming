# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import Counter
class Solution:
    def solve (self, root, string):
        if (root == None):
            return 0
        if (root.left == None and root.right == None):
            # check if string has even number of values
            string += str(root.val)
            flag = 2
            string = list(string)
            string.sort()
            # print(string)
            c = Counter(string).values()
            for i in c:
                if flag == 0:
                    return 0
                if i%2 == 1:
                    flag -=1
            # if flag not 0
            if flag == 0:
                return 0
            else:
                return 1
        else:
            # print("string is " + string + str(root.val))
            return self.solve(root.left, string + str(root.val)) + self.solve
                (root.right, string + str(root.val))
        def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        return self.solve (root, "")
                