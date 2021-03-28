class Solution:
    def specialArray(self, nums: List[int]) -> int:
        for i in range(1,len(nums)+1):
            # print(i)
            count = 0
            for j in range(len(nums)):
                if nums[j] >= i:
                    count +=1
                    if count > i:
                        # print(i, count)
                        break
            if count == i:
                # print(i, count)
                return count
        return -1
        