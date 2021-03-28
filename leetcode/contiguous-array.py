class Solution(object):
    def findMaxLength(self, nums):
        nums = [-1 if j == 0 else 1 for j in nums]
        count = 0
        d = {} 
        ans = 0
        for i in range(len(nums)):
            if count not in d:
                d[count] = i
            else:
                if (i - d[count] > ans):
                    ans = i - d[count]
            count += nums[i]
        # one extra time
        i = len(nums)
        if count not in d:
            d[count] = i
        else:
            if (i - d[count] > ans):
                ans = i - d[count]
        return ans
                                                # [1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0]