from collections import Counter
class Solution(object):
    def findLucky(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
                temp1 = Counter(arr).keys()
        temp2 = Counter(arr).values()
        ans = -1
        for i in range(len(temp1)):
            if temp1[i] == temp2[i] and temp1[i] > ans:
                ans = temp1[i]
        return ans
                            