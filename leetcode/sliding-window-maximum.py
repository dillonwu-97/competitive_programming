from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        current_max = -10e4
        ret = []
        q = deque([nums[0]])
        i = 1
        while (i < k):
            # print(q[-1])
            while len(q) > 0 and nums[i] > q[-1]:
                q.pop()
            q.append(nums[i])
            i+=1
        # continuation
        for i in range(len(nums)-k+1):
            if i == 0:
                ret.append(q[0])
                continue
            if nums[i-1] == q[0]:
                q.popleft()
            while len(q) > 0 and nums[i+k-1] > q[-1]: q.pop()
            q.append(nums[i+k-1])
            ret.append(q[0])
        return ret
                                                                                                    # print(nums[i:i+k])
            # print(current_max)
#             if nums[i+k-1] > current_max and i!=0:
#                 current_max = nums[i+k-1]
#                 ret.append(current_max)
# #             this part is too slow; need to find a way to keep track of 
    maxes more efficiently
#             # elif i == 0 or nums[i-1] == current_max:
#             #     q = nums[i:i+k]
#             #     heapq._heapify_max(q)
#             #     current_max = heappop(q)
#             #     ret.append(current_max)
#             else:
#                 ret.append(current_max)
#         return ret