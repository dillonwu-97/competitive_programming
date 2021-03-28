class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        def counting_sort(array1):
            shift = abs(min(array1))
            array1 = list(map(lambda x: x + shift, array1))
            # print(array1)
                        m = max(array1) + 1
            count = [0] * m                
            for a in array1:
            # count occurences
                count[a] += 1   
                        ret = 0
            current = 0
            for i in range(len(count)):
                if count[i]:
                    current+=1
                else:
                    if current > ret:
                        ret = current
                    current = 0
            if current > ret: return current
            return ret
                if len(nums) == 0:
            return 0
        return counting_sort(nums)