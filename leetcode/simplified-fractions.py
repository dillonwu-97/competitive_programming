import math
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        sol = []
        for i in range(1,n+1):
            for j in range(1,i):
                if math.gcd(i, j) != 1 and j!=1:
                    continue
                else:
                    s = str(j) + "/" + str(i)
                    sol.append(s)
        return sol