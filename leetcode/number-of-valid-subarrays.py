class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
                s = []
        ret = 0
        for i in range(len(nums)):
            # print(s)
            if len(s) == 0 or nums[i] > s[-1][1]:
                s.append((i, nums[i]))
            else:
                while len(s) > 0 and nums[i] < s[-1][1]:
                    ret += (i - s.pop()[0])
                s.append((i, nums[i]))
        while len(s) > 0:
            ret += (len(nums) - s.pop()[0])
        return ret
                # slow
#         ret = 0
#         for i in range(len(nums)):
#             start = nums[i]
#             # ret.append([start])
#             ret +=1
#             for j in range(i + 1, len(nums)):
#                 # print(nums[j], start, j)
#                 if nums[j] >= start:
#                     ret+=1
#                     # ret.append(nums[i:j+1])
#                 else:
#                     break
#         return ret
            