class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if len(text2) > len(text1):
            temp = text2
            text2 = text1
            text1 = temp
        dp = [[0]*len(text1) for i in range (len(text2))]
                for j in range(len(text1)):
            for i in range(len(text2)):
                if text2[i] == text1[j]:
                    if i == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j-1])
                else:
                    if i == 0:
                        dp[i][j] = dp[i][j-1]
                    else:
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        # print(len(dp), len(dp[0]))
        # for i in dp:
        #     print(i)
        return dp[-1][-1]