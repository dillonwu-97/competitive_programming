class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # if len(nums) > max(nums):
            # return False
        if len(nums) <= 1:
            return True
        if nums[0] == 0:
            return False
                cur = nums[0]
        for i in range(1,len(nums)-1):
            cur = max(nums[i], cur-1)
            if cur == 0:
                return False
        return True
                                                    # DP solution - too long
        # Basically checking if you can skip the zeros
#         t = [-1] * len(nums)
#         def solve(start):
#             if t[start] == 0:
#                 return False
#             if nums[start] == 0:
#                 t[start] = 0
#                 return False
#             elif nums[start] >= len(nums)-1:
#                 return True
#             for j in range(nums[start],0,-1): # do bigger number first
#             # for j in range(1,nums[start]):
#                 if start + j >= len(nums)-1:
#                     return True
#                 elif t[start + j] == 0:
#                     continue
#                 else:
#                     ret = True and solve(start+j)
#                     if ret == True:
#                         return True
#                     else:
#                         continue
#             t[start] = 0
#             return False
               #         # sol = None
#         # for i in range(len(nums)):
#         #     sol = solve(i)
#         #     if sol == True:
#         #         break
        #         return solve(0)