from collections import Counter
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        seen = {}
        res = n
        flag = 1
        while(res!= 1):
            if res not in seen:
                seen[res] = 1
            else:
                flag = 0
                break
            # print(res)
            new = str(res)
            res = 0
            for i in new:
                # print(i)
                res+= int(i)**2
                        if flag == 0: return False
        else: return True
                            