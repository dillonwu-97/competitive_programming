class Solution(object):
    def createTargetArray(self, nums, index):
        """
        :type nums: List[int]
        :type index: List[int]
        :rtype: List[int]
        """
        out = []
        for i in range(len(nums)):
            out.insert(index[i],nums[i])
        return out