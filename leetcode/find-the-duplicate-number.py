class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = 0
        sol = 0
        for i in nums:
            temp = 2 ** (i-1)
            t1 = n >> i-1
            if t1 ^ 1 < t1: # if this bit has not been flipped before
                sol = i
                break
            n ^= temp
            return sol
            