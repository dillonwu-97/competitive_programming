from collections import Counter
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stack.append(i)
            if len(stack) == 0:
                return False
            if i == ')':
                if stack[-1] != '(':
                    return False
                stack.pop()
            if i == ']':
                if stack[-1] != '[':
                    return False
                stack.pop()
            if i == '}':
                if stack[-1] != '{':
                    return False
                stack.pop()
        if len(stack) >= 1:
            return False
        return True
                                        # b = len(s) - 1
        # a = 0
        # if len(s) % 2 == 1:
        #     return False
        # while (a < b):
        #     if s[a] == '(' and s[b] != ')':
        #         return False
        #     elif s[a] == '[' and s[b] != ']':
        #         return False
        #     elif s[a] == '{' and s[b] != '}':
        #         return False
        #     a+=1
        #     b-=1
        # return True
                #         d = Counter()
#         for i in s:
#             if i == '(' or i == '[' or i == '{':
#                 d[i] += 1
#             elif i == ')':
#                 d['('] -= 1
#             elif i == ']':
#                 d['['] -=1
#             elif i == '}':
#                 d['{'] -=1
#         if max(d.values()) == 0:
#             return True
#         else:
#             return False
                