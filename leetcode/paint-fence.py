class Solution:
    def numWays(self, n: int, k: int) -> int:
        t = k*k
        if n == 0:
            return 0
        if n <=2:
            return k ** n
                single = k
        double = k * (k-1)    
                # for k = 3
        # 1 single => 2 doubles
        # 2 doubles => 4 doubles, 2 singles
        for i in range(n-2):
            temp = double
            double = double * (k-1) + single * (k-1) # works for 3's
            single = temp
            t = single + double
        return t
        