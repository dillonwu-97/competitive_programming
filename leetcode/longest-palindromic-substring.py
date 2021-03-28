class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return ""
        elif len(s) == 1:
            return s
        def isp(s):
            if s == s[::-1]:
                return True
            else:
                return False
        m = None
        ml = 0
#         for i in range(len(s)):
#             for j in range(i, len(s)+1):
#                 if i == j: continue
#                 curr = s[i:j]
#                 if isp(curr):
#                     if len(curr) > ml:
#                         ml = len(curr)
#                         m = (i, j)
#         return s[m[0]:m[1]]
        # handling odds 
        for i in range(len(s)):
            for j in range(i+1):      
                # print(i, j, i+j, i-j)
                if i + j >= len(s):
                    if len(s[i-j+1:i+j]) > ml:
                        ml = len(s[i-j+1:i+j])
                        m = s[i-j+1:i+j]
                    break
                elif j == i and s[0] == s[i+j]:
                    if 2*i > ml:
                        ml = 2*i
                        m = s[0:i+j+1]
                    break
                        # i think i can add a break here as well
                elif s[i+j] != s[i-j]:
                    # print(i, j, i+j, i-j)
                    if 2*(j-1) > ml:
                        m = s[i-j + 1:i+j]
                        ml = 2 * (j-1)
                    # print(m, ml)
                    break
        # handling even palindromes
        for i in range(len(s)):
            for j in range(i+1):
                # print(i, j, i+j+1, i-j)
                if i + j+1 >= len(s):
                    temp = s[i-j+1:i+j+1]
                    if len(temp) > ml:
                        ml = len(temp)
                        m = temp
                    break
                elif j==i and s[0] == s[i+j+1]:
                    # print(i, j, i+j+1, i-j)
                    temp = s[0:i+j+1+1]
                    if len(temp) > ml:
                        ml = len(temp)
                        m = temp
                    break
                if s[i-j] != s[i+j+1]:
                    temp = s[i-j+1: i+j+1]
                    if len(temp) > ml:
                        ml = len(temp)
                        m = temp
                    break
        return m
                                