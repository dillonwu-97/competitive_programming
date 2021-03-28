class Solution(object):
    def sumFourDivisors(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        h = max(nums) + 1 # 0 -> max
        spf = [i for i in range(h)] # store smallest prime factors
        for i in range(4,h,2): 
            spf[i] = 2
        for i in range (3, h):
            if spf[i] == i:
                for j in range(i * i, h, i):
                    spf[j] = i
        yes = []
        for i in nums:
            count = [1]
            while i!= 1:
                count.append(i)
                count.append(spf[i])
                i /= spf[i]  
            if len(set(count)) == 4:
                yes.append(sum(set(count)))
        return sum(yes)
                    