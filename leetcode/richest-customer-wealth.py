class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        m = 0
        for i in range (len(accounts)):
            if sum(accounts[i]) > m:
                m = sum(accounts[i])
        return m