class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        # faster version
        t = [0] * (len(arr)+1)
        # t[0] = arr[0]
        for i in range(len(arr)+1):
            for j in range(1,k+1):
                if i - j >= 0:
                    if i -j == 0:
                        t[i] = max ( max(arr[i-j:i]) * j, t[i])
                    else:
                        ret = t[i-j] + (max(arr[i-j:i]) * j)
                        t[i] = max(t[i], ret)
        # print(t)
        return t[-1]
                        # too slow
        # d = {}
        # # bruteforce strategy:
        # def solve(arr, k, start, end):
        #     # print(len(arr))
        #     if len(arr[start:end]) <= k:
        #         ret = max(arr[start:end]) * (end-start)
        #         if (start, end) in d:
        #             return d[(start, end)]
        #         else:
        #             d[(start, end)] = ret
        #             return ret
        #     else:
        #         ret = 0 # max value
        #         if (start, end) in d:
        #             return d[(start, end)]
        #         for j in range(1,k+1):
        #             left = solve(arr, k, start, start+j)
        #             right = solve(arr, k, start+j, end)
        #             s = left + right
        #             if s > ret:
        #                 ret = s
        #         d[(start,end)] = ret    
        #         return ret
        # ret = solve(arr, k, 0, len(arr))
        # # print(d)
        # return ret