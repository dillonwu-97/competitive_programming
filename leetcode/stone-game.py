class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True
        #         t = [[0] * len(piles) for i in range(len(piles))]
        #         k = 0
#         for k in range(len(piles)):
#             for i in range(len(piles)-k):
#                 if i == i+k:
#                     t[i][i+k] = (piles[i], 0)
#                 else:
#                     # print(k, piles[i+k], t[i][i+k-1])
#                     # left side, then down side
#                     t[i][i+k] = max( (piles[i+k] + t[i][i+k-1][1], t[i][i+k
    -1][0]), (piles[i] +t[i+1][i+k][1], t[i+1][i+k][0] ))
#         if t[0][-1][0] > t[0][-1][1]:
#             return True
#         return False