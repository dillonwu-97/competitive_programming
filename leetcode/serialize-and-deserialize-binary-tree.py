# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import OrderedDict, defaultdict
class Codec:
    def serialize(self, root) -> str:
        """Encodes a tree to a single string.
                :type root: TreeNode
        :rtype: str
        """
        # two dictionaries, key with corresponding value and key with 
            children
                if root == None:
            return "zip"
        d_val = {}
        d_child = {}
        def getValues(root):
            if root:
                k = len(d_val)
                d_val[k] = root.val
                left = getValues(root.left)
                right = getValues(root.right)
                if (left != None or right != None):
                    d_child[k] = [left, right]
                return k
        getValues(root)
        # print(d_val)
        # print(d_child)
        s = ""
        for k in d_val.keys():
            s += str(k) + ":" + str(d_val[k]) + ";"
        s+="#"
        for k in d_child.keys():
            s += str(k) + ":" + str(d_child[k])[1:-1] + ";"
        return s # add root.val so i know where to start
            def deserialize(self, data):
        """Decodes your encoded data to tree.
                :type data: str
        :rtype: TreeNode
        """
                if data == "zip":
            return None
        s = data
        temp = s.split("#")
        s_keys = temp[0][:-1]
        s_child = temp[1][:-1]
        # print(s_keys, s_child)
        d_keys = {}
        d_child = defaultdict(list)
        # constructing key dictionary
        dt = s_keys.split(";")
        for i in range (len(dt)):
            temp = dt[i].split(":")
            d_keys[int(temp[0])] = int(temp[1])
        # print(d_keys)
                if (len(s_child) > 0):
                        dt = s_child.split(";")
            for i in range(len(dt)):
                temp = dt[i].split(":")
                k = int(temp[0])
                values = temp[1].split(",")
                for i in range(len(values)):
                    try:
                        d_child[k].append(int(values[i]))
                    except:
                        d_child[k].append(None)
            # print(d_child)
                start = 0
        def construct(start):
            ret = TreeNode()
            if start not in d_keys:
                return None
            ret.val = d_keys[start]
            # print(ret.val)
            if start in d_child:
                for i in range(len(d_child[start])):
                    if i == 0:
                        ret.left = construct(d_child[start][i])
                    else:
                        ret.right = construct(d_child[start][i])
            return ret  
        finalReturn = construct(start)      
        return finalReturn
                        # Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()