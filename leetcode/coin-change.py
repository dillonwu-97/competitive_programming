class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Try #3: dp, but with only 1 row and go through each coin for each 
            amount
        if amount == 0:
            return 0
        t = [-1] * (amount+1)
        t = [0] + [float('inf')] * amount
        # coins.sort()
        for i in range(1,amount+1):
            for j in range(len(coins)):
                # perfect modulo
                if i >= coins[j]:
                    t[i] = min(t[i], t[i-coins[j]] + 1)
        return t[-1] if t[-1]!= float('inf') else -1
                                # coins.sort(reverse=True)
        # t = 0
        # print(coins)
        # for i in range(len(coins)):
        #     if amount > coins[i]:
        #         t += amount // coins[i]
        #         amount -= amount % coins[i]
        # if amount != 0:
        #     return -1
        # return t
                # Try #2:
        # if amount == 0:
        #     return 0
        # # This should be dp
        # coins.sort()
        # # print(coins)
        # # t = [[-1]*amount]*len(coins)
        # t = [[-1 for i in range(amount)] for j in range(len(coins))]
        # for i in range(len(coins)):
        #     for j in range(amount):
        #         modtemp = (j+1) % coins[i]
        #         divtemp = (j+1) // coins[i]
        #         # flag = 'hi'
        #         if i > 0:  
        #             if t[i-1][j] != -1:
        #                 # no remainders after dividing by current
        #                 if modtemp == 0:
        #                     t[i][j] = min(divtemp, t[i-1][j])
        #                 else:
        #                     # flag = 'abcde'
        #                     # cant user remainder square because nothing 
            there
        #                     if t[i][modtemp-1] == -1:
        #                         t[i][j] = t[i-1][j]
        #                     else:
        #                     # print('testing', divtemp, t[i][modtemp], t[i
            -1][j])
        #                         t[i][j] = min(divtemp + t[i][modtemp-1], t[i
            -1][j])
        #                     # print('testing cont ', t[i][j])
        #             else:
        #                 if modtemp == 0:
        #                     t[i][j] = divtemp
        #                 else:
        #                     if t[i][modtemp-1] != -1:
        #                         t[i][j] = divtemp + t[i][modtemp-1]
        #                     # else keep as -1
        #                 # if (j+1) % coins[i] == 0:
        #                     # t[i][j] = (j+1)//coins[i]
        #         else:
        #             if modtemp == 0:
        #                 t[i][j] = divtemp
        #         # if t[i][j] == 0:
        #         #     print(modtemp, divtemp, coins[i], j)
        # # print(t)
        # print(t[2][1223], 1643 % (408 * 3), t[3][418],t[3][1223])
        # return t[-1][-1]
        #408 * 3 + 419
        