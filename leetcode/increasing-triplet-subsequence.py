import sys
class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return False
        m1_val = nums[0]
        m2_val = sys.maxsize
        for i in range(1,len(nums)):
            if nums[i] > m2_val:
                return True
            if nums[i] < m1_val:
                m1_val = nums[i]
            if nums[i] > m1_val and nums[i] < m2_val:
                m2_val = nums[i]
                        return False