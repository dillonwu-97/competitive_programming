class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)
                t = [0] * len(nums)
        for i in range(len(nums)):
            m = 0
            for j in range(i-1, -1, -1):
                # print(nums[i], nums[j], t[i], m)
                if nums[i] > nums[j] and t[j] >= m:
                    m = t[j]
            t[i] = m + 1
            # print(t)
        return max(t)
                        