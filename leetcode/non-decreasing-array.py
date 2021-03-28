import random
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if len(nums) <= 2:
            return True
        c = 0
        s = [nums[0]]
        for i in range(1,len(nums)):
            # flip current
            if len(s) >= 2 and nums[i] < s[-1] and nums[i] < s[-2]:
                c+=1
            # else flip prev
            else:
                if len(s) > 0 and nums[i] < s[-1]:
                    s.pop()
                    c+=1
                s.append(nums[i])
            if c >= 2:
                return False
        return True
                                    #         c = 0
#         if nums[1] < nums[0] and nums[1] > nums[2]: 
#             c+=1
#         for i in range(2,len(nums)):
#             if nums[i] < nums[i-1] or nums[i] < nums[i-2]:
#                 c +=1 
#             if c >= 2:
#                 return False
            #         return True
                