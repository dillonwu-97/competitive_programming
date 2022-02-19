class Solution:
    def reverse(self, x: int) -> int:
        ma = pow(2, 31) - 1
        mn = pow(2, 31) * -1
        n = str(x)
        r = n[::-1]
        if r[-1] == '-':
            r = '-' + r[:-1]
                if int(r) > ma:
            return 0
        if int(r) < mn:
            return 0
        return int(r)