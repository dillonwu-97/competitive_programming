import sys
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        mi = sys.maxsize
        ma = prices[0]
        vals = [0] * len(prices)
        for i in range(len(prices)):
            if prices[i] < mi:
                mi = prices[i]
            vals[i] = prices[i] - mi
        return max(vals)
                                            