class Solution:
    def minWindow(self, s: str, t: str) -> str:
        s0 = s
        s1 = t
        total = len(s1)
        d = Counter(s1) # all letters of d; keep subtracting these
        best_i = 0
        best_j = 0
        i = 0
        for j in range(len(s0)):
        # keep track of the total numbers we have left
        # print(total)
            if d[ s0[j] ] > 0:
                total -= 1
            d[ s0[j] ] -= 1 # create buffer for the letters we can get rid of
            # found a valid string so get rid of characters from the left
            if total == 0:
            # print("total is: ", total)
                while (i <= j and d[s0[i]] < 0):
                # print("test")
                    if d[ s0[i] ] < 0:
                        d[ s0[i] ] += 1
                        i+=1
                if (best_j == 0) or (j - i < best_j - best_i):
                    best_j = j+1
                    best_i = i
            # print(d)
            # print(best_i, best_j)
            # print(s0[best_i: best_j])
        return s0[best_i:best_j]