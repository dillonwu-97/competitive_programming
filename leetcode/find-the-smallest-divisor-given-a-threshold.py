class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        # naiive solution
        mi = 1 # return answer
        c = 0 # current
        start = 0
        end = max(nums)
        # for i in range(1, max(nums)):
        while(start < end):
            i = (start + end) // 2
            if i == 0:
                start = 1
                break
            # print(i)
            temp = [nums[j]//i if nums[j]%i==0 else nums[j]//i +1 for j in 
                range(len(nums))]
            c = sum(temp)
            # print(start, end, i, c)
            # if c is greater than the treshold, go right
            if c > threshold:
                start = i +1
            else:
                end = i
            # if c is less than the threshold, go left
                        return start
                                                                    