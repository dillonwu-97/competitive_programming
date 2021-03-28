class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        d = {}
        for i in range(len(string.ascii_lowercase)):
            d[string.ascii_lowercase[i]] = (i//5, i%5)
        start = d['a']
        ret = ""
        for i in range(len(target)):
            end = d[ target[i] ]
            xdist = abs(end[0] - start[0])
            ydist = abs(end[1] - start[1])
            # special case
            if target[i] == 'z' and ydist > 0 and end[0] > start[0]:
                ret += "D" * (xdist -1)
                if end[1] > start[1]:
                    ret += "R" * ydist
                else:
                    ret += "L" * ydist
                ret += "D"
            else:
                if end[0] > start[0]:
                    ret += "D" * xdist
                else:
                    ret += "U" * xdist
                # print(ret)
                if end[1] > start[1]:
                    ret += "R" * ydist
                else:
                    ret += "L" * ydist
            ret += "!"
            start = end
        return ret
            