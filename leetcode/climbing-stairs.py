class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return n
        t = [0] * n
        t[0] = 1
        t[1] = 2
        for i in range(2,n):
            t[i] = t[i-1] + t[i-2]
        return t[n-1]
        