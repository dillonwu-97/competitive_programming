class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        # if even, ignore, else split on odds
        # observation: all odd numbers work, but need to remove the duplicates
        # 2n = k * (2x+k+1)
        ret = 0
        N *= 2
        r = int(sqrt(N))
        for i in range(1,r+1):
            # k = i 
            if (N % i == 0):
                temp = (N // i) - i - 1
                if temp % 2 == 0:
                    # print(temp)
                    ret+=1
        return ret
                                                        # sliding window but too slow
        # if N <= 1: return N
        # t = 0
        # ret = 0
        # edge = 1
        # i = 1
        # while (i != N+1):
        #     if t < N:
        #         t += i
        #         i +=1
        #         if t == N:
        #             t -= edge
        #             edge += 1
        #             ret += 1
        #     elif t > N:
        #         t -= edge
        #         edge += 1
        #         if t == N:
        #             t += i
        #             i += 1
        #             ret += 1
        # return ret + 1
                        