class Solution:
    def numDecodings(self, s: str) -> int:
                        # takes too long
        def solve(s):
            if len(s) > 0 and s[0] == "0":
                return 0
            elif len(s) > 1 and int(s[:2]) >= 27:
                return solve(s[1:])
            elif len(s) == 0 or len(s) == 1:
                return 1
            else:
                return solve(s[1:]) + solve(s[2:])
        # edge cases are annoying
        if len(s) < 10:
            return solve(s)
        else:
            if len(s) == 1:
                if s == "0":
                    return 0
                else:
                    return 1
            t = [0] * (len(s)+1)
            t[0] = 1
            if int(s[:2]) >= 27:
                if s[1] == "0":
                    return 0
                t[1] = 1
            else:
                if int(s[:2]) != 10 and int(s[:2]) != 20:
                    t[1] = 2
                else:
                    t[1] = 1
            for i in range(2, len(s)):
                # maybe not like staircase
                if int(s[i]) == 0:
                    if (int(s[i-1]) == 1 or int(s[i-1]) == 2):
                        t[i] = t[i-1]
                    else:
                        return 0
                elif int(s[i-1]) < 3 and int(s[i]) < 7 and int(s[i-1]) != 0:
                    t[i] = t[i-1] + t[i-2]
                elif int(s[i-1]) == 1:
                    t[i] = t[i-1] + t[i-2]
                else:
                    t[i] = t[i-1]
            # print(t)
            return t[len(s)-1]
            