class Solution:
    def convert(self, s: str, numRows: int) -> str:
                if (numRows == 1): return s
                ret = ""
        start = 0
        gap = (numRows - 1) * 2
        gap2 = 0
        # Start
        while (start < len(s)):
            # print("start is ", start)
            ret += s[start]
            start += gap
                # Middle
        start = 1
        while (gap > 2):
            gap -= 2
            gap2 += 2
            current = start
            # print(start, gap, gap2)
            while (current < len(s)):
                ret += s[current]
                current += gap
                if current >= len(s): break
                ret += s[current]
                current += gap2
            start += 1
                # End
        # print(start)
        while (start < len(s)):
            ret += s[start]
            start += ((numRows - 1) * 2)
                # print(ret)
        return ret
            