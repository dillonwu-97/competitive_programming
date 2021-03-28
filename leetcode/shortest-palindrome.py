class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # do with both rolling hash and kmp
                def ispal(s):
            if s[::-1] == s:
                return True
                index = 0
        if ispal(s) == True:
            return s
        for i in range(len(s)):
            if ispal(s[:i]):
                index = i
        ret = s[index:][::-1] + s
        return ret
                                            #         ## skipping results in bug
#         ## Solution below times out
#         if len(set(s)) == 1:
#             return s
#         # need to handle both odd and even palindrome possibility
#         i = 0
#         j = 0
#         ret = s[::-1] + s
#         # even length of string
#         if len(s) % 2 == 0:
#             # even palindrome best
#             left = len(s) // 2 -1 
#             right = len(s) // 2
            #             # if i == -1, then break
#             i = left
#             while (i > -1):
#                 # print(i)
#                 j = i + 1
#                 # print(i, j, s[i], s[j])
#                 flag = 0
#                 while (i >= 0 and s[i] == s[j]):
#                     i-=1
#                     j+=1
#                     flag = 1
#                 # if i is -1, then we can stop
#                 if i == -1:
#                     temp = s[j:][::-1] + s
#                     if len(temp) < len(ret):
#                         ret = temp
#                     # print("even even ", ret)    
#                     break
#                 # if i is 0, then this means we need to flip from position 
    0
#                 elif i == 0:
#                     temp = s[1:][::-1] + s
#                     if len(temp) < len(ret):
#                         ret = temp
#                     # print(ret)
#                     break
                    #                 if flag == 0: i -= 1
            #             # odd palindrome best, len(s)//2 - 1 is the pivot
#             # print("even even ", ret) 
#             left = len(s) // 2 - 2 # skip the middle value, and pretend 
    that is the pivot
#             right = len(s) // 2
#             i = left
#             while (i > -1):
#                 print(i)
#                 j = i + 2
#                 flag = 0
#                 while (i >= 0 and s[i] == s[j]):
#                     i-=1
#                     j+=1
#                     flag = 1
                #                 if i == -1:
#                     temp = s[j:][::-1] + s
#                     if len(temp) < len(ret):
#                         ret= temp
#                     # print(ret)
#                     break
#                 if flag == 0: i-=1
#         else:
#             # even palindrome best
#             left = len(s) // 2 - 1
#             right = left + 1
#             i = left
#             while (i > -1):
#                 j = i + 1
#                 flag = 0
#                 while (i >= 0 and s[i]==s[j]):
#                     i -=1
#                     j +=1
#                     flag = 1
#                 if i == -1:
#                     temp = s[j:][::-1] + s
#                     if len(temp) < len(ret):
#                         ret = temp
#                     break
#                 elif i ==0:
#                     temp = s[1:][::-1] + s
#                     if len(temp) < len(ret):
#                         ret = temp
#                     break
#                 if flag == 0: i-=1
#             # odd palindrome best
#             left = len(s) // 2 - 1
#             right = left + 2
            #             i = left
#             while (i > -1):
#                 j = i + 2
#                 flag = 0
#                 while(i >= 0 and s[i] == s[j]):
#                     flag = 1
#                     i-=1
#                     j+=1
#                 # no need for -1 case
#                 if i == -1:
#                     temp = s[j:][::-1] + s
#                     if len(temp) < len(ret):
#                         ret = temp
#                     break
#                 elif i == 0:
#                     temp = s[1:][::-1] + s
#                     if len(temp) < len(ret):
#                         ret = temp
#                     break
#                 if flag == 0: i-=1