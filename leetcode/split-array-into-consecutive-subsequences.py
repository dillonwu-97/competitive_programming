from collections import Counter
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        nlist = Counter(nums)
        d = Counter(nums)
        end = Counter()
        for i in nums:
            if d[i] == 0:
                # print(i, " is 0")
                continue
            if i-1 in end and end[i-1] > 0:
                # print(i)
                end[i] +=1 
                d[i] -=1
                end[i-1] -=1
            elif d[i] > 0 and d[i+1] > 0 and d[i+2] > 0:
                d[i] -= 1
                d[i+1] -=1
                d[i+2] -=1
                end[i+2] += 1
            else:
                # print(i, d, end)
                return False
        return True
                        #         newd = Counter()
#         # find the 3sets first
#         # but you can also form fewer 3sets
#         # d = {k:v for k,v in sorted(d.items(), key= lambda item: item[1])}
#         for i in nums:
#             if i in d and i+1 in d and i+2 in d and d[i] > 0 and d[i+1] > 0 
    and d[i+2] > 0:
#                 d[i] -=1
#                 d[i+1] -=1
#                 d[i+2] -=1
#                 newd[i+2] += 1
#             else:
#                 continue
#         newset = []
#         # d = {k:v for k,v in sorted(d.items(), key= lambda item: item[1])}
#         for k in d.keys():
#             if d[k] > 0:
#                 newset += [k] * d[k]
#         # print(newset)
#         # try to fill in the rest
#         for i in newset:
#             if i-1 in newd:
#                 if newd[i-1] <= 1:
#                     del newd[i-1]
#                 else:
#                     newd[i-1] -=1
#                 newd[i] += 1
#             else:
#                 # print(i, newd)
#                 return False
#         return True
                        