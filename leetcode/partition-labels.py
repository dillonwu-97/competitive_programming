from collections import defaultdict
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        d = {}
        for i in range(len(S)):
            if S[i] not in d:
                d[ S[i] ] = [i, i]
            else:
                d[ S[i] ][1] = i
        dsorted = [v for k, v in sorted(d.items(), key = lambda item:item[1])]
        ret = []
        # print(dsorted)
        cur_start = dsorted[0][0]
        cur_fin = dsorted[0][1]
        for i in dsorted:
            if i[0] > cur_fin:
                ret.append(cur_fin - cur_start + 1)
                cur_start = i[0]
                cur_fin = i[1]
            elif i[1] > cur_fin:
                cur_fin = i[1]
        ret.append(cur_fin - cur_start+ 1)
                        return ret