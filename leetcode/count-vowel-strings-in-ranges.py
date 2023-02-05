class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        count = []
        c = ['a','e','i','o','u']
        for i in words:
            if i[0] in c and i[-1] in c:
                count.append(1)
            else:
                count.append(0)
                count = [0] + count
        for i in range(1,len(count)):
            if count[i] == 1:
                count[i] = count[i-1] + 1
            else:
                count[i] = count[i-1]
                    ret = []
        for i,v in enumerate(queries):
            ret.append(count[v[1] + 1] - count[v[0]])
                return ret