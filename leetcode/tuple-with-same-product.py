from collections import Counter
class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        d = Counter()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                d[nums[i] * nums[j]] += 1
        ret = 0
        # print(d)
        for i in d.keys():
            if d[i] > 1:
                ret += (d[i] - 1)  * d[i] // 2
        return ret * 8