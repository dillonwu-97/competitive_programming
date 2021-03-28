class Solution:
    def decodeString(self, s: str) -> str:
        def isint(s):
            try:
                s = int(s)
                return True
            except:
                return False
        def solve(s, count, start):
            # start recursion at "["
            # end recursion at "]"
            ret = ""
            i = start
            n=""
            while (i < len(s)):
                if isint(s[i]):
                    n=""
                    while (s[i].isdigit()):
                        n+=s[i]
                        i+=1
                    # skip the number and [ sign 
                    i-= 1
                    n = int(n)
                    count +=1
                    out = solve(s, count, i+2) 
                    ret += out[0] * n
                    i = out[1]
                    count -=1
                    while (s[i] != "]"):
                        i+=1
                    if count == 0:
                        return ret
                # return ret
                elif s[i] == "[":
                    continue
                elif s[i] == "]":
                    return [ret, i] 
                                        else:
                    ret += s[i]
                i+=1
        s = "1[" + s + "]"
        # print(s)
        return solve(s,0, 0)