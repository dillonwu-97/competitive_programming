class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # subset sums?
        total = []
        cur = 0
        for i in nums:
            cur+=i
            total.append(cur)
        d = {}
        d[0] = 1
        res = 0
        # print(total)
        for i in total:
            if i-k in d: 
                res+= d[i-k]
            if i in d:
                d[i] +=1
            else: 
                d[i] = 1
            # if i+k in d:
            #     res += d[i+k]
            # print(res)
        # print(d)
        return res
                            #[2,-3,2,3,-2,2,2]
                