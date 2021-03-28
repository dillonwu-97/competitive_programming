def swap(a, b, arr):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp
    class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        start = 0
        zero = 0
        two = len(nums) - 1
        flag = 0
        while (start < two + 1):
            # reduce space we need to check first 
            if flag == 0:
                while (two > -1 and nums[two] == 2):
                    two-=1
                while (zero < len(nums) and nums[zero] == 0):
                    zero +=1
                    start +=1
            flag = 1
            if (two < 0 or zero == len(nums) or two < zero):
                break
            if nums[start] == 2 and start != two:
                swap(start, two,nums)
                two -=1 # next two goes here
                # check again in case the swapped value was also a 2
                while nums[start] == 2 and start <= two:
                    swap(start, two,nums)
                    two -=1 # next two goes here
            if nums[start] == 0:
                swap(start, zero, nums)
                zero +=1 # next zero goes here
            start +=1
            # print(nums, start, zero, two)
                                                                                                