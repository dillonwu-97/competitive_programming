class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        m= n
        n = abs(n)
        sol = 1
        while(n!= 0):
            if n%2 == 1: sol*=x
            x*=x
            n//=2
        if m < 0:
            sol = 1/sol
        return sol
                    