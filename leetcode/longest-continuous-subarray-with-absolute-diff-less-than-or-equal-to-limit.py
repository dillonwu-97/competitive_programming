class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
                def findmin(a, start, end):
            min_val = 99999999
            min_dex = 0
            for i in range(start, end):
                if a[i] < min_val:
                    min_val = a[i]
                    min_dex = i
            return min_dex
            def findmax(a, start, end):
            max_val = -1
            max_dex = 0
            for i in range(start, end):
                if a[i] > max_val:
                    max_val = a[i]
                    max_dex = i
            return max_dex
                            ret = 0
        max_val = nums[0]
        min_val = nums[0]
        # max_dex = 0
        # min_dex = 0
        i = 0
        j = 1
        # better strategy is to work backwards from j to find next value 
            within limit
        while j < len(nums):
            # print(nums[j], max_val, min_val)
            if abs(nums[j] - max_val) > limit or abs(nums[j] - min_val) > 
                limit:
                i = j
                max_val = -1
                min_val = 999999999
                while( abs(nums[i] - nums[j]) <= limit):
                    if nums[i] > max_val:
                        max_val = nums[i]
                    if nums[i] < min_val:
                        min_val = nums[i]
                    i-=1
                i+= 1
            else:
                if (nums[j] > max_val):
                    max_val = nums[j]
                if (nums[j] < min_val):
                    min_val = nums[j]
            if j - i > ret:
                ret = j - i
            j+= 1
        return ret + 1
                                        # while j < len(nums)-1:
        #     while abs(nums[j] - max_val) > limit:
        #         max_dex = find_max(nums, max_dex+1, j+1)
        #         max_val = nums[max_dex]
        #         # there also needs to be a restricted range
        #     while abs(nums[j] - min_val) > limit:
        #         min_dex = find_min(nums, min_dex+1, j+1)
        #         min_val = nums[min_dex]
        #     i = max(max_dex, min_dex)
        #     if j - i > ret:
        #         ret = j - i
        # return ret 
                                                                                                    