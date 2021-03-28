class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        cur = 0
        ret = ""
        for i in range(len(s)):
            if s[i] == '(':
                cur +=1 
            elif s[i] == ')':
                cur -=1
            if cur >= 0:
                ret += s[i]
            else:
                cur += 1
        # get rid of end
        if cur > 0:
            for i in range(len(ret)-1, -1, -1):
                if ret[i] == '(':
                    cur -=1
                    ret = ret[:i] + ret[i+1:]
                if cur == 0:
                    break
                        return ret