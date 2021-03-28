class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> 
        List[str]:
        if len(nums) == 0:
            if lower == upper:
                return [str(lower)]
            else:
                return [str(lower) + '->' + str(upper)]
        res = []
        if lower +1 == nums[0]:
            res.append(str(lower))
        elif lower < nums[0] + 1 and lower != nums[0]:
            res.append(str(lower) + '->' + str(nums[0] - 1))
                for i in range(1,len(nums)):
            if nums[i] == nums[i-1]:
                continue
            low = nums[i-1] + 1
            up = nums[i] - 1
            if low == nums[i]:
                continue
            if low == up:
                res.append(str(low))
            else:
                res.append(str(low) + '->' + str(up))
        if nums[len(nums) - 1] + 1 < upper:
            res.append(str(nums[len(nums)-1] + 1) + '->' + str(upper))
        elif nums[len(nums) -1] + 1 == upper:
            res.append(str(upper))
        return res
                