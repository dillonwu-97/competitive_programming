class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        n = str(n) #string,
        n = list(n) #list of chars
        product = 1
        summ = 0
        for i in range(len(n)):
            product = product * int(n[i])
            summ = summ + int(n[i])
        return product - summ
                