class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        cp = cardPoints
        def solve(cp, k):
            m = sum(cp[:k])
            d = [m] * len(cp)
            mindex = cp.index(min(cp[:k]))
            # mindex = k-1
            left = mindex
            left_to_add = left + 1
            right = mindex + 1
            for i in range(k, len(cp)):
                # print(left, right, m)
                # print(m)
                if cp[left] < cp[right] and left != -1:
                    m = m - cp[left] + cp[i]
                    left_to_add = left
                    left = max(-1, left - 1)
                else:
                    m = m - cp[right] + cp[i]
                    right += 1
                    while right < i and cp [right] < cp[left_to_add]:
                        m = m - cp[right] + cp[left_to_add]
                        left_to_add += 1
                        left += 1
                        right += 1
            return m
        #[8,5,9,8,6,7,6]        
        # print(len(cp))
        # print(m, d, mindex)
        # print(d[k-1], m)
        # print(sum(cp[:k]), sum(cp[len(cp)-k:]),solve(cp, k), solve(cp[::-1]
            ,k))
        def solve2(cp, k):
            m = sum(cp[:k])
            if k == len(cp):
                return m
            cur = m
            for i in range(k):
                # print(cur, cp[k-1-i], cp[len(cp)-i-1])
                cur = cur - cp[k-1-i] + cp[len(cp)-i-1]
                # print(cur)
                m = max(cur, m)
            return m
                                        return solve2(cp,k)
        # return max(sum(cp[:k]), sum(cp[len(cp)-k:]),solve(cp, k), solve(cp[
            ::-1],k))
                