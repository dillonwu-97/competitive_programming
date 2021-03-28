from collections import Counter
import heapq
class Solution:
    def reorganizeString(self, S: str) -> str:
        d = Counter(S)
        h = []
        for i, j in d.most_common():
            heappush(h, (-1*j, i))
        ret = ""
        while(len(h) > 0):
            # print(h)
            a = heappop(h)
            if len(ret) != 0 and a[1] == ret[-1]:
                try:
                    b = heappop(h)
                    ret += b[1]
                    heappush(h, (a[0], a[1]))
                    if b[0] != -1:
                        heappush(h, (b[0]+1, b[1]))
                except:
                    return ""
            else:
                ret += a[1]
                if (a[0] != -1):
                    heappush(h, (a[0]+1, a[1]))
                return ret
                ## doesnt work for "eeehhhqqq"
        # def solve(S):
        #     if len(S) <= 2:
        #         return S
        #     ret = S[0]
        #     i = 1 
        #     j = 2
        #     while i < len(S):
        #         if i == j: j+=1
        #         if S[i] == '0':
        #             i+=1 
        #             continue
        #         if S[i] == ret[-1]:
        #             while (j < len(S) and (ret[-1] == S[j] or S[j] == '0')):
        #                 j+=1
        #             if j >= len(S): 
        #                 print(i, j, S[i:j])
        #                 return ""
        #             ret += S[j]
        #             S = S[:j] + '0' + S[j+1:]
        #             j+=1
        #         else:
        #             ret += S[i]
        #             S = S[:i] + '0' + S[i+1:]
        #             i+=1
        #     return ret
        # ret = solve(S)
        # return ret
                            