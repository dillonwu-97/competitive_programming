class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        a = [i[0] for i in edges]
        b = [i[1] for i in edges]
        c = a + b
        d = Counter(c)
        return max(d, key= lambda x: d[x])