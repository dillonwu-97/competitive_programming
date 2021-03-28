class Solution:
    def findReplaceString(self, S: str, indexes: List[int], sources: List[str]
        , targets: List[str]) -> str:
                ret = ""
        i = 0
        j = 0
        z = zip(indexes, sources, targets)
        n = sorted(z, key = lambda x:x[0])
        while (i < len(S)):
            # print(ret)
            if j < len(n) and i == n[j][0]:
                len_of_source = len(n[j][1])
                rep = S[n[j][0]: n[j][0] + len_of_source]
                if rep == n[j][1]:
                    ret += n[j][2]
                else:
                    ret+=S[i:i+len(n[j][1])]
                i+=len(n[j][1])
                j+=1
            else:
                ret+=S[i]
                i+=1
                # print(ret)
        return ret