class Solution:
    def rob(self, nums: List[int]) -> int:
        a = [0] * len(nums)
        if (len(a) == 0):
            return 0
        elif (len(a) == 1):
            return nums[0]
        elif (len(a) == 2):
            return max(nums[0], nums[1])
        a[0] = nums[0]
        a[1] = max(nums[1], nums[0])
        for i in range(2, len(nums)):
            a[i] = max(a[i-1], a[i-2] + nums[i])
        # print(a)
        return a[len(nums)-1]
                    