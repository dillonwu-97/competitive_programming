class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        count = 0
        track = 0
        if len(nums) == 0:
            return 0
        for i in range(nums[0], nums[len(nums)-1]):
            if count == k:
                return i - 1
            elif i == nums[track]:
                track +=1
                continue
            else:
                count +=1
        return nums[len(nums)-1] + k - count
        