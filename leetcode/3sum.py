from collections import Counter
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        #  naive solution
        # sol = []
        # seen = {}
        # for i in range(len(nums)):
        #     for j in range(i+1, len(nums)):
        #         for k in range(j+1, len(nums)):
        #             if nums[i] + nums[j] + nums[k] == 0:
        #                 temp = [nums[i], nums[j], nums[k]]
        #                 temp.sort()
        #                 v = str(temp)
        #                 if v not in seen:
        #                     seen[v] = 0
        #                     sol.append(list(temp))
        # return sol
                sol = []
        nums.sort()
        # print(nums)
        visited = Counter()
        # seen = Counter()
        for i in range(len(nums)):
            if nums[i] in visited:
                continue
            else:
                visited[nums[i]] = 0
            j = i+1
            k = len(nums) - 1
            while (j < k):
                s = nums[i] + nums[j] + nums[k]
                # print(i, j, k, s)
                if s == 0:
                    sol.append([nums[i], nums[j], nums[k]])
                    prev = nums[j]
                    while(j < len(nums) and nums[j]== prev):
                        j+=1 
                    prev = nums[k]
                    while(k >= i and nums[k] == prev):
                        k-=1
                elif s < 0:
                    prev = nums[j]
                    while(j < len(nums) and nums[j] == prev):
                        j+=1 
                elif s > 0:
                    prev = nums[k]
                    while(k >= i and nums[k] == prev):
                        k-=1
                              return sol
                    